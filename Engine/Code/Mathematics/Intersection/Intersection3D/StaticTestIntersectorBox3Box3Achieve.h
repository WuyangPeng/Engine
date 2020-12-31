///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/25 10:24)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H

#include "IntersectorUtility3.h"
#include "StaticTestIntersectorBox3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Box3<Real>::StaticTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, const Real epsilon)
    : ParentType{ epsilon }, m_Box0{ box0 }, m_Box1{ box1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorBox3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Box3<Real>::Test()
{
    /// ����֮��ĽǶȵ�����ֵ�Ľ�ֵֹ�� ���ڲ�׽����һ����ƽ�е������
    /// ���������������������������Cross(A[i],B[j]) ����ķ��롣
    constexpr auto cutoff = Math::GetValue(1) - Math::GetZeroTolerance();
    auto existsParallelPair = false;

    // ��������ĵĲ D = C1 - C0��
    auto centerDiff = m_Box1.GetCenter() - m_Box0.GetCenter();

    // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
    Matrix3<Real> matrix{};
    // |c_{ij}|
    Matrix3<Real> absMatrix{};
    // Dot(A_i,D)
    Vector3D axisDotCenterDiff{};

    constexpr auto size = 3;

    // �� C0 + t * A0
    for (auto i = 0; i < size; ++i)
    {
        matrix(0, i) = Vector3DTools::DotProduct(m_Box0.GetAxis(0), m_Box1.GetAxis(i));
        absMatrix(0, i) = Math::FAbs(matrix(0, i));
        if (cutoff < absMatrix(0, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[0] = Vector3DTools::DotProduct(m_Box0.GetAxis(0), centerDiff);

    /// ����뾶������֮��ľ���
    auto r = Math::FAbs(axisDotCenterDiff[0]);
    auto r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 0>() + m_Box1.GetExtent(1) * absMatrix.GetValue<0, 1>() + m_Box1.GetExtent(2) * absMatrix.GetValue<0, 2>();
    auto r01 = m_Box0.GetExtent(0) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1
    for (auto i = 0; i < size; ++i)
    {
        matrix(1, i) = Vector3DTools::DotProduct(m_Box0.GetAxis(1), m_Box1.GetAxis(i));
        absMatrix(1, i) = Math::FAbs(matrix(1, i));
        if (cutoff < absMatrix(1, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[1] = Vector3DTools::DotProduct(m_Box0.GetAxis(1), centerDiff);
    r = Math::FAbs(axisDotCenterDiff[1]);
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<1, 0>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 1>() + m_Box1.GetExtent(2) * absMatrix.GetValue<1, 2>();
    r01 = m_Box0.GetExtent(1) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2
    for (auto i = 0; i < 3; ++i)
    {
        matrix(2, i) = Vector3DTools::DotProduct(m_Box0.GetAxis(2), m_Box1.GetAxis(i));
        absMatrix(2, i) = Math::FAbs(matrix(2, i));
        if (cutoff < absMatrix(2, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[2] = Vector3DTools::DotProduct(m_Box0.GetAxis(2), centerDiff);
    r = Math::FAbs(axisDotCenterDiff[2]);
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<2, 0>() + m_Box1.GetExtent(1) * absMatrix.GetValue<2, 1>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 2>();
    r01 = m_Box0.GetExtent(2) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B0
    r = Math::FAbs(Vector3DTools::DotProduct(m_Box1.GetAxis(0), centerDiff));
    auto r0 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 0>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 0>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 0>();
    r01 = r0 + m_Box1.GetExtent(0);
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0+ t * B1
    r = Math::FAbs(Vector3DTools::DotProduct(m_Box1.GetAxis(1), centerDiff));
    r0 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 1>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 1>();
    r01 = r0 + m_Box1.GetExtent(1);
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B2
    r = Math::FAbs(Vector3DTools::DotProduct(m_Box1.GetAxis(2), centerDiff));
    r0 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 2>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 2>();
    r01 = r0 + m_Box1.GetExtent(2);
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // ����һ�Ժ�����ƽ�еģ������2D�з�������Ч�ģ����м�顰��Ե���������Է���С�
    if (existsParallelPair)
    {
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // �� C0 + t * A0 x B0
    r = Math::FAbs(axisDotCenterDiff[2] * matrix.GetValue<1, 0>() - axisDotCenterDiff[1] * matrix.GetValue<2, 0>());
    r0 = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 0>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 0>();
    r1 = m_Box1.GetExtent(1) * absMatrix.GetValue<0, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<0, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B1
    r = Math::FAbs(axisDotCenterDiff[2] * matrix.GetValue<1, 1>() - axisDotCenterDiff[1] * matrix.GetValue<2, 1>());
    r0 = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 1>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 1>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<0, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B2
    r = Math::FAbs(axisDotCenterDiff[2] * matrix.GetValue<1, 2>() - axisDotCenterDiff[1] * matrix.GetValue<2, 2>());
    r0 = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 2>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 2>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<0, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B0
    r = Math::FAbs(axisDotCenterDiff[0] * matrix.GetValue<2, 0>() - axisDotCenterDiff[2] * matrix.GetValue<0, 0>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 0>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 0>();
    r1 = m_Box1.GetExtent(1) * absMatrix.GetValue<1, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<1, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B1
    r = Math::FAbs(axisDotCenterDiff[0] * matrix.GetValue<2, 1>() - axisDotCenterDiff[2] * matrix.GetValue<0, 1>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 1>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 1>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<1, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<1, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B2
    r = Math::FAbs(axisDotCenterDiff[0] * matrix.GetValue<2, 2>() - axisDotCenterDiff[2] * matrix.GetValue<0, 2>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 2>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 2>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<1, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B0
    r = Math::FAbs(axisDotCenterDiff[1] * matrix.GetValue<0, 0>() - axisDotCenterDiff[0] * matrix.GetValue<1, 0>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 0>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 0>();
    r1 = m_Box1.GetExtent(1) * absMatrix.GetValue<2, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B1
    r = Math::FAbs(axisDotCenterDiff[1] * matrix.GetValue<0, 1>() - axisDotCenterDiff[0] * matrix.GetValue<1, 1>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 1>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 1>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<2, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B2
    r = Math::FAbs(axisDotCenterDiff[1] * matrix.GetValue<0, 2>() - axisDotCenterDiff[0] * matrix.GetValue<1, 2>());
    r0 = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 2>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 2>();
    r1 = m_Box1.GetExtent(0) * absMatrix.GetValue<2, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<2, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H