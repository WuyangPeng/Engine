///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:16)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticTestIntersectorBox3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Box3<Real>::StaticTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, const Real epsilon)
    : ParentType{ epsilon }, box0{ box0 }, box1{ box1 }
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
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box0;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Box3<Real>::Test()
{
    /// ����֮��ĽǶȵ�����ֵ�Ľ�ֵֹ�� ���ڲ�׽����һ����ƽ�е������
    /// ���������������������������Cross(A[i],B[j]) ����ķ��롣
    constexpr auto cutoff = MathType::GetValue(1) - MathType::GetZeroTolerance();
    auto existsParallelPair = false;

    // ��������ĵĲ D = C1 - C0��
    auto centerDiff = box1.GetCenter() - box0.GetCenter();

    // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
    Matrix3<Real> matrix{};
    // |c_{ij}|
    Matrix3<Real> absMatrix{};
    // Dot(A_i,D)
    Vector3 axisDotCenterDiff{};

    constexpr auto size = 3;

    // �� C0 + t * A0
    for (auto i = 0; i < size; ++i)
    {
        matrix(0, i) = Vector3Tools::DotProduct(box0.GetAxis(0), box1.GetAxis(i));
        absMatrix(0, i) = MathType::FAbs(matrix(0, i));
        if (cutoff < absMatrix(0, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[0] = Vector3Tools::DotProduct(box0.GetAxis(0), centerDiff);

    /// ����뾶������֮��ľ���
    auto r = MathType::FAbs(axisDotCenterDiff[0]);
    auto r1 = box1.GetExtent(0) * absMatrix.template GetValue<0, 0>() + box1.GetExtent(1) * absMatrix.template GetValue<0, 1>() + box1.GetExtent(2) * absMatrix.template GetValue<0, 2>();
    auto r01 = box0.GetExtent(0) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1
    for (auto i = 0; i < size; ++i)
    {
        matrix(1, i) = Vector3Tools::DotProduct(box0.GetAxis(1), box1.GetAxis(i));
        absMatrix(1, i) = MathType::FAbs(matrix(1, i));
        if (cutoff < absMatrix(1, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[1] = Vector3Tools::DotProduct(box0.GetAxis(1), centerDiff);
    r = MathType::FAbs(axisDotCenterDiff[1]);
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<1, 0>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 1>() + box1.GetExtent(2) * absMatrix.template GetValue<1, 2>();
    r01 = box0.GetExtent(1) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2
    for (auto i = 0; i < 3; ++i)
    {
        matrix(2, i) = Vector3Tools::DotProduct(box0.GetAxis(2), box1.GetAxis(i));
        absMatrix(2, i) = MathType::FAbs(matrix(2, i));
        if (cutoff < absMatrix(2, i))
        {
            existsParallelPair = true;
        }
    }
    axisDotCenterDiff[2] = Vector3Tools::DotProduct(box0.GetAxis(2), centerDiff);
    r = MathType::FAbs(axisDotCenterDiff[2]);
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<2, 0>() + box1.GetExtent(1) * absMatrix.template GetValue<2, 1>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 2>();
    r01 = box0.GetExtent(2) + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B0
    r = MathType::FAbs(Vector3Tools::DotProduct(box1.GetAxis(0), centerDiff));
    auto r0 = box1.GetExtent(0) * absMatrix.template GetValue<0, 0>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 0>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 0>();
    r01 = r0 + box1.GetExtent(0);
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0+ t * B1
    r = MathType::FAbs(Vector3Tools::DotProduct(box1.GetAxis(1), centerDiff));
    r0 = box1.GetExtent(0) * absMatrix.template GetValue<0, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 1>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 1>();
    r01 = r0 + box1.GetExtent(1);
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B2
    r = MathType::FAbs(Vector3Tools::DotProduct(box1.GetAxis(2), centerDiff));
    r0 = box1.GetExtent(0) * absMatrix.template GetValue<0, 2>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 2>();
    r01 = r0 + box1.GetExtent(2);
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
    r = MathType::FAbs(axisDotCenterDiff[2] * matrix.template GetValue<1, 0>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 0>());
    r0 = box0.GetExtent(1) * absMatrix.template GetValue<2, 0>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 0>();
    r1 = box1.GetExtent(1) * absMatrix.template GetValue<0, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<0, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B1
    r = MathType::FAbs(axisDotCenterDiff[2] * matrix.template GetValue<1, 1>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 1>());
    r0 = box0.GetExtent(1) * absMatrix.template GetValue<2, 1>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 1>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<0, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<0, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B2
    r = MathType::FAbs(axisDotCenterDiff[2] * matrix.template GetValue<1, 2>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 2>());
    r0 = box0.GetExtent(1) * absMatrix.template GetValue<2, 2>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 2>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<0, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<0, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B0
    r = MathType::FAbs(axisDotCenterDiff[0] * matrix.template GetValue<2, 0>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 0>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<2, 0>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 0>();
    r1 = box1.GetExtent(1) * absMatrix.template GetValue<1, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<1, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B1
    r = MathType::FAbs(axisDotCenterDiff[0] * matrix.template GetValue<2, 1>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 1>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<2, 1>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 1>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<1, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<1, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B2
    r = MathType::FAbs(axisDotCenterDiff[0] * matrix.template GetValue<2, 2>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 2>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<2, 2>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 2>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<1, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B0
    r = MathType::FAbs(axisDotCenterDiff[1] * matrix.template GetValue<0, 0>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 0>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<1, 0>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 0>();
    r1 = box1.GetExtent(1) * absMatrix.template GetValue<2, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 1>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B1
    r = MathType::FAbs(axisDotCenterDiff[1] * matrix.template GetValue<0, 1>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 1>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<1, 1>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 1>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<2, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B2
    r = MathType::FAbs(axisDotCenterDiff[1] * matrix.template GetValue<0, 2>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 2>());
    r0 = box0.GetExtent(0) * absMatrix.template GetValue<1, 2>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 2>();
    r1 = box1.GetExtent(0) * absMatrix.template GetValue<2, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<2, 0>();
    r01 = r0 + r1;
    if (r01 < r)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H