///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/24 18:05)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H

#include "DynamicTestIntersectorBox3Box3.h"
#include "StaticTestIntersectorBox3Box3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DynamicTestIntersectorBox3Box3<Real>::DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Box0{ box0 }, m_Box1{ box1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorBox3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorBox3Box3<Real>::Test()
{
    if (Vector3DTools::Approximate(this->GetLhsVelocity(), this->GetRhsVelocity()))
    {
        StaticTestIntersectorBox3Box3<Real> intersector{ m_Box0, m_Box1 };
        this->SetIntersectionType(intersector.GetIntersectionType());
        if (intersector.IsIntersection())
        {
            this->SetContactTime(Math::GetValue(0));
            return;
        }
        return;
    }

    /// ����֮��ĽǶȵ�����ֵ�Ľ�ֵֹ�� ���ڲ�׽����һ����ƽ�е������
    /// �������������������������������Խ��з��롣
    constexpr auto cutoff = Math::GetValue(1) - Math::GetZeroTolerance();
    auto existsParallelPair = false;

    // ��������
    auto centerDiff = m_Box1.GetCenter() - m_Box0.GetCenter();
    auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();

    // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
    const Matrix3<Real> matrix{ Vector3DTools::DotProduct(m_Box0.GetAxis(0), m_Box1.GetAxis(0)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(0), m_Box1.GetAxis(1)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(0), m_Box1.GetAxis(2)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(1), m_Box1.GetAxis(0)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(1), m_Box1.GetAxis(1)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(1), m_Box1.GetAxis(2)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(2), m_Box1.GetAxis(0)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(2), m_Box1.GetAxis(1)),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(2), m_Box1.GetAxis(2)) };

    // |c_{ij}|
    Matrix3<Real> absMatrix{ Math::FAbs(matrix.GetValue<0, 0>()),
                             Math::FAbs(matrix.GetValue<0, 1>()),
                             Math::FAbs(matrix.GetValue<0, 2>()),
                             Math::FAbs(matrix.GetValue<1, 0>()),
                             Math::FAbs(matrix.GetValue<1, 1>()),
                             Math::FAbs(matrix.GetValue<1, 2>()),
                             Math::FAbs(matrix.GetValue<2, 0>()),
                             Math::FAbs(matrix.GetValue<2, 1>()),
                             Math::FAbs(matrix.GetValue<2, 2>()) };
    // Dot(A_i,D)
    Vector3D axisDotCenterDiff{ Vector3DTools::DotProduct(m_Box0.GetAxis(0), centerDiff),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(1), centerDiff),
                                Vector3DTools::DotProduct(m_Box0.GetAxis(2), centerDiff) };

    // Dot(A_i,W)
    Vector3D axisDotAvelocityDiff{ Vector3DTools::DotProduct(m_Box0.GetAxis(0), velocityDiff),
                                   Vector3DTools::DotProduct(m_Box0.GetAxis(1), velocityDiff),
                                   Vector3DTools::DotProduct(m_Box0.GetAxis(2), velocityDiff) };

    this->SetContactTime(Math::GetValue(0));
    Separated tlast{ false, Math::sm_MaxReal };

    // �� C0 + t * A[i]
    constexpr auto size = 3;
    for (auto i = 0; i < size; ++i)
    {
        for (auto j = 0; j < size; ++j)
        {
            if (cutoff < absMatrix[i][j])
            {
                existsParallelPair = true;
                break;
            }
        }
    }

    for (auto i = 0; i < size; ++i)
    {
        auto min0 = -m_Box0.GetExtent(i);
        auto max0 = +m_Box0.GetExtent(i);
        auto radius = m_Box1.GetExtent(0) * absMatrix(i, 0) + m_Box1.GetExtent(1) * absMatrix(i, 1) + m_Box1.GetExtent(2) * absMatrix(i, 2);
        auto min1 = axisDotCenterDiff[i] - radius;
        auto max1 = axisDotCenterDiff[i] + radius;
        auto speed = axisDotAvelocityDiff[i];

        tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
        if (tlast.first)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // �� C0 + t * B[i]
    for (auto i = 0; i < size; ++i)
    {
        auto radius = m_Box0.GetExtent(0) * absMatrix(0, i) + m_Box0.GetExtent(1) * absMatrix(1, i) + m_Box0.GetExtent(2) * absMatrix(2, i);
        auto min0 = -radius;
        auto max0 = +radius;
        auto center = Vector3DTools::DotProduct(m_Box1.GetAxis(i), centerDiff);
        auto min1 = center - m_Box1.GetExtent(i);
        auto max1 = center + m_Box1.GetExtent(i);
        auto speed = Vector3DTools::DotProduct(velocityDiff, m_Box1.GetAxis(i));
        tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
        if (tlast.first)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    /// ����һ�Ժе�����ƽ�еģ������2D�з�������Ч�ģ����м�顰��Ե���������Է�����ӡ�
    if (existsParallelPair)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // �� C0 + t * A0 x B0
    auto radius = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 0>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 0>();
    auto min0 = -radius;
    auto max0 = +radius;
    auto center = axisDotCenterDiff[2] * matrix.GetValue<1, 0>() - axisDotCenterDiff[1] * matrix.GetValue<2, 0>();
    radius = m_Box1.GetExtent(1) * absMatrix.GetValue<0, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<0, 1>();
    auto min1 = center - radius;
    auto max1 = center + radius;
    auto speed = axisDotAvelocityDiff[2] * matrix.GetValue<1, 0>() - axisDotAvelocityDiff[1] * matrix.GetValue<2, 0>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B1
    radius = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 1>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[2] * matrix.GetValue<1, 1>() - axisDotCenterDiff[1] * matrix.GetValue<2, 1>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<0, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[2] * matrix.GetValue<1, 1>() - axisDotAvelocityDiff[1] * matrix.GetValue<2, 1>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A0 x B2
    radius = m_Box0.GetExtent(1) * absMatrix.GetValue<2, 2>() + m_Box0.GetExtent(2) * absMatrix.GetValue<1, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[2] * matrix.GetValue<1, 2>() - axisDotCenterDiff[1] * matrix.GetValue<2, 2>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<0, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<0, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[2] * matrix.GetValue<1, 2>() - axisDotAvelocityDiff[1] * matrix.GetValue<2, 2>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B0
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 0>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 0>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.GetValue<2, 0>() - axisDotCenterDiff[2] * matrix.GetValue<0, 0>();
    radius = m_Box1.GetExtent(1) * absMatrix.GetValue<1, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<1, 1>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.GetValue<2, 0>() - axisDotAvelocityDiff[2] * matrix.GetValue<0, 0>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1 x B1
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 1>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.GetValue<2, 1>() - axisDotCenterDiff[2] * matrix.GetValue<0, 1>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<1, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<1, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.GetValue<2, 1>() - axisDotAvelocityDiff[2] * matrix.GetValue<0, 1>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1xB2
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<2, 2>() + m_Box0.GetExtent(2) * absMatrix.GetValue<0, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.GetValue<2, 2>() - axisDotCenterDiff[2] * matrix.GetValue<0, 2>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<1, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<1, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.GetValue<2, 2>() - axisDotAvelocityDiff[2] * matrix.GetValue<0, 2>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B0
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 0>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 0>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.GetValue<0, 0>() - axisDotCenterDiff[0] * matrix.GetValue<1, 0>();
    radius = m_Box1.GetExtent(1) * absMatrix.GetValue<2, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 1>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.GetValue<0, 0>() - axisDotAvelocityDiff[0] * matrix.GetValue<1, 0>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B1
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 1>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.GetValue<0, 1>() - axisDotCenterDiff[0] * matrix.GetValue<1, 1>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<2, 2>() + m_Box1.GetExtent(2) * absMatrix.GetValue<2, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.GetValue<0, 1>() - axisDotAvelocityDiff[0] * matrix.GetValue<1, 1>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A2 x B2
    radius = m_Box0.GetExtent(0) * absMatrix.GetValue<1, 2>() + m_Box0.GetExtent(1) * absMatrix.GetValue<0, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.GetValue<0, 2>() - axisDotCenterDiff[0] * matrix.GetValue<1, 2>();
    radius = m_Box1.GetExtent(0) * absMatrix.GetValue<2, 1>() + m_Box1.GetExtent(1) * absMatrix.GetValue<2, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.GetValue<0, 2>() - axisDotAvelocityDiff[0] * matrix.GetValue<1, 2>();
    tlast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tlast.second);
    if (tlast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorBox3Box3<Real>::Separated Mathematics::DynamicTestIntersectorBox3Box3<Real>::IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real tlast) noexcept
{
    auto invSpeed = Math::GetValue(0);
    auto t = Math::GetValue(0);

    // box1���λ��box0�����
    if (max1 < min0)
    {
        if (speed <= Math::GetValue(0))
        {
            // ͶӰ������롣
            return { true, tlast };
        }
        invSpeed = (Math::GetValue(1)) / speed;

        t = (min0 - max1) * invSpeed;
        if (this->GetContactTime() < t)
        {
            this->SetContactTime(t);
        }

        if (tmax < this->GetContactTime())
        {
            // �����ָ��ʱ���ڲ��ཻ��
            return { true, tlast };
        }

        t = (max0 - min1) * invSpeed;
        if (t < tlast)
        {
            tlast = t;
        }

        if (tlast < this->GetContactTime())
        {
            // �����ϲ�һ�µ�ʱ�䡪�������޷��ཻ��
            return { true, tlast };
        }
    }
    // box1���λ��box0���Ҳ�
    else if (max0 < min1)
    {
        if (speed >= Math::GetValue(0))
        {
            // ͶӰ������롣
            return { true, tlast };
        }
        invSpeed = (Math::GetValue(1)) / speed;

        t = (max0 - min1) * invSpeed;
        if (this->GetContactTime() < t)
        {
            this->SetContactTime(t);
        }

        if (tmax < this->GetContactTime())
        {
            // �����ָ��ʱ���ڲ��ཻ��
            return { true, tlast };
        }

        t = (min0 - max1) * invSpeed;
        if (t < tlast)
        {
            tlast = t;
        }

        if (tlast < this->GetContactTime())
        {
            // �����ϲ�һ�µ�ʱ�䡪�������޷��ཻ��
            return { true, tlast };
        }
    }
    // box0��box1����ص�
    else
    {
        if (Math::GetValue(0) < speed)
        {
            t = (max0 - min1) / speed;
            if (t < tlast)
            {
                tlast = t;
            }

            if (tlast < this->GetContactTime())
            {
                // �����ϲ�һ�µ�ʱ�䡪�������޷��ཻ��
                return { true, tlast };
            }
        }
        else if (speed < Math::GetValue(0))
        {
            t = (min0 - max1) / speed;
            if (t < tlast)
            {
                tlast = t;
            }

            if (tlast < this->GetContactTime())
            {
                // �����ϲ�һ�µ�ʱ�䡪�������޷��ཻ��
                return { true, tlast };
            }
        }
    }

    return { false, tlast };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H