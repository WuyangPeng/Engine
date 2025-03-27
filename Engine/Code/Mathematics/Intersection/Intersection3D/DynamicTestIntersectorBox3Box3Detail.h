///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:15)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicTestIntersectorBox3Box3.h"
#include "StaticTestIntersectorBox3Box3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::DynamicTestIntersectorBox3Box3<Real>::DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, box0{ box0 }, box1{ box1 }
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
Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box0;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorBox3Box3<Real>::Test()
{
    if (Vector3Tools::Approximate(this->GetLhsVelocity(), this->GetRhsVelocity()))
    {
        StaticTestIntersectorBox3Box3<Real> intersector{ box0, box1 };
        this->SetIntersectionType(intersector.GetIntersectionType());
        if (intersector.IsIntersection())
        {
            this->SetContactTime(MathType::GetValue(0));
            return;
        }
        return;
    }

    /// 框轴之间的角度的余弦值的截止值。 用于捕捉至少一对轴平行的情况。
    /// 如果发生这种情况，则无需包括叉积轴以进行分离。
    constexpr auto cutoff = MathType::GetValue(1) - MathType::GetZeroTolerance();
    auto existsParallelPair = false;

    // 便利变量
    auto centerDiff = box1.GetCenter() - box0.GetCenter();
    auto velocityDiff = this->GetRhsVelocity() - this->GetLhsVelocity();

    // matrix C = A^T B, c_{ij} = Dot(A_i,B_j)
    const Matrix3<Real> matrix{ Vector3Tools::DotProduct(box0.GetAxis(0), box1.GetAxis(0)),
                                Vector3Tools::DotProduct(box0.GetAxis(0), box1.GetAxis(1)),
                                Vector3Tools::DotProduct(box0.GetAxis(0), box1.GetAxis(2)),
                                Vector3Tools::DotProduct(box0.GetAxis(1), box1.GetAxis(0)),
                                Vector3Tools::DotProduct(box0.GetAxis(1), box1.GetAxis(1)),
                                Vector3Tools::DotProduct(box0.GetAxis(1), box1.GetAxis(2)),
                                Vector3Tools::DotProduct(box0.GetAxis(2), box1.GetAxis(0)),
                                Vector3Tools::DotProduct(box0.GetAxis(2), box1.GetAxis(1)),
                                Vector3Tools::DotProduct(box0.GetAxis(2), box1.GetAxis(2)) };

    // |c_{ij}|
    Matrix3<Real> absMatrix{ MathType::FAbs(matrix.template GetValue<0, 0>()),
                             MathType::FAbs(matrix.template GetValue<0, 1>()),
                             MathType::FAbs(matrix.template GetValue<0, 2>()),
                             MathType::FAbs(matrix.template GetValue<1, 0>()),
                             MathType::FAbs(matrix.template GetValue<1, 1>()),
                             MathType::FAbs(matrix.template GetValue<1, 2>()),
                             MathType::FAbs(matrix.template GetValue<2, 0>()),
                             MathType::FAbs(matrix.template GetValue<2, 1>()),
                             MathType::FAbs(matrix.template GetValue<2, 2>()) };
    // Dot(A_i,D)
    Vector3 axisDotCenterDiff{ Vector3Tools::DotProduct(box0.GetAxis(0), centerDiff),
                               Vector3Tools::DotProduct(box0.GetAxis(1), centerDiff),
                               Vector3Tools::DotProduct(box0.GetAxis(2), centerDiff) };

    // Dot(A_i,W)
    Vector3 axisDotAvelocityDiff{ Vector3Tools::DotProduct(box0.GetAxis(0), velocityDiff),
                                  Vector3Tools::DotProduct(box0.GetAxis(1), velocityDiff),
                                  Vector3Tools::DotProduct(box0.GetAxis(2), velocityDiff) };

    this->SetContactTime(MathType::GetValue(0));
    Separated tLast{ false, MathType::maxReal };

    // 轴 C0 + t * A[i]
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
        auto min0 = -box0.GetExtent(i);
        auto max0 = +box0.GetExtent(i);
        auto radius = box1.GetExtent(0) * absMatrix(i, 0) + box1.GetExtent(1) * absMatrix(i, 1) + box1.GetExtent(2) * absMatrix(i, 2);
        auto min1 = axisDotCenterDiff[i] - radius;
        auto max1 = axisDotCenterDiff[i] + radius;
        auto speed = axisDotAvelocityDiff[i];

        tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
        if (tLast.first)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 轴 C0 + t * B[i]
    for (auto i = 0; i < size; ++i)
    {
        auto radius = box0.GetExtent(0) * absMatrix(0, i) + box0.GetExtent(1) * absMatrix(1, i) + box0.GetExtent(2) * absMatrix(2, i);
        auto min0 = -radius;
        auto max0 = +radius;
        auto center = Vector3Tools::DotProduct(box1.GetAxis(i), centerDiff);
        auto min1 = center - box1.GetExtent(i);
        auto max1 = center + box1.GetExtent(i);
        auto speed = Vector3Tools::DotProduct(velocityDiff, box1.GetAxis(i));
        tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
        if (tLast.first)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    /// 至少一对盒的轴是平行的，因此在2D中分离是有效的，其中检查“边缘”法线足以分离盒子。
    if (existsParallelPair)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // 轴 C0 + t * A0 x B0
    auto radius = box0.GetExtent(1) * absMatrix.template GetValue<2, 0>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 0>();
    auto min0 = -radius;
    auto max0 = +radius;
    auto center = axisDotCenterDiff[2] * matrix.template GetValue<1, 0>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 0>();
    radius = box1.GetExtent(1) * absMatrix.template GetValue<0, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<0, 1>();
    auto min1 = center - radius;
    auto max1 = center + radius;
    auto speed = axisDotAvelocityDiff[2] * matrix.template GetValue<1, 0>() - axisDotAvelocityDiff[1] * matrix.template GetValue<2, 0>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A0 x B1
    radius = box0.GetExtent(1) * absMatrix.template GetValue<2, 1>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[2] * matrix.template GetValue<1, 1>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 1>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<0, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<0, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[2] * matrix.template GetValue<1, 1>() - axisDotAvelocityDiff[1] * matrix.template GetValue<2, 1>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A0 x B2
    radius = box0.GetExtent(1) * absMatrix.template GetValue<2, 2>() + box0.GetExtent(2) * absMatrix.template GetValue<1, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[2] * matrix.template GetValue<1, 2>() - axisDotCenterDiff[1] * matrix.template GetValue<2, 2>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<0, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<0, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[2] * matrix.template GetValue<1, 2>() - axisDotAvelocityDiff[1] * matrix.template GetValue<2, 2>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A1 x B0
    radius = box0.GetExtent(0) * absMatrix.template GetValue<2, 0>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 0>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.template GetValue<2, 0>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 0>();
    radius = box1.GetExtent(1) * absMatrix.template GetValue<1, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<1, 1>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.template GetValue<2, 0>() - axisDotAvelocityDiff[2] * matrix.template GetValue<0, 0>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A1 x B1
    radius = box0.GetExtent(0) * absMatrix.template GetValue<2, 1>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.template GetValue<2, 1>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 1>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<1, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<1, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.template GetValue<2, 1>() - axisDotAvelocityDiff[2] * matrix.template GetValue<0, 1>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A1xB2
    radius = box0.GetExtent(0) * absMatrix.template GetValue<2, 2>() + box0.GetExtent(2) * absMatrix.template GetValue<0, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[0] * matrix.template GetValue<2, 2>() - axisDotCenterDiff[2] * matrix.template GetValue<0, 2>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<1, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<1, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[0] * matrix.template GetValue<2, 2>() - axisDotAvelocityDiff[2] * matrix.template GetValue<0, 2>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A2 x B0
    radius = box0.GetExtent(0) * absMatrix.template GetValue<1, 0>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 0>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.template GetValue<0, 0>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 0>();
    radius = box1.GetExtent(1) * absMatrix.template GetValue<2, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 1>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.template GetValue<0, 0>() - axisDotAvelocityDiff[0] * matrix.template GetValue<1, 0>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A2 x B1
    radius = box0.GetExtent(0) * absMatrix.template GetValue<1, 1>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 1>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.template GetValue<0, 1>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 1>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<2, 2>() + box1.GetExtent(2) * absMatrix.template GetValue<2, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.template GetValue<0, 1>() - axisDotAvelocityDiff[0] * matrix.template GetValue<1, 1>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A2 x B2
    radius = box0.GetExtent(0) * absMatrix.template GetValue<1, 2>() + box0.GetExtent(1) * absMatrix.template GetValue<0, 2>();
    min0 = -radius;
    max0 = +radius;
    center = axisDotCenterDiff[1] * matrix.template GetValue<0, 2>() - axisDotCenterDiff[0] * matrix.template GetValue<1, 2>();
    radius = box1.GetExtent(0) * absMatrix.template GetValue<2, 1>() + box1.GetExtent(1) * absMatrix.template GetValue<2, 0>();
    min1 = center - radius;
    max1 = center + radius;
    speed = axisDotAvelocityDiff[1] * matrix.template GetValue<0, 2>() - axisDotAvelocityDiff[0] * matrix.template GetValue<1, 2>();
    tLast = IsSeparated(min0, max0, min1, max1, speed, this->GetTMax(), tLast.second);
    if (tLast.first)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
typename Mathematics::DynamicTestIntersectorBox3Box3<Real>::Separated Mathematics::DynamicTestIntersectorBox3Box3<Real>::IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real tlast) noexcept
{
    auto invSpeed = MathType::GetValue(0);
    auto t = MathType::GetValue(0);

    // box1最初位于box0的左侧
    if (max1 < min0)
    {
        if (speed <= MathType::GetValue(0))
        {
            // 投影间隔分离。
            return { true, tlast };
        }
        invSpeed = (MathType::GetValue(1)) / speed;

        t = (min0 - max1) * invSpeed;
        if (this->GetContactTime() < t)
        {
            this->SetContactTime(t);
        }

        if (tmax < this->GetContactTime())
        {
            // 间隔在指定时间内不相交。
            return { true, tlast };
        }

        t = (max0 - min1) * invSpeed;
        if (t < tlast)
        {
            tlast = t;
        }

        if (tlast < this->GetContactTime())
        {
            // 物理上不一致的时间——对象无法相交。
            return { true, tlast };
        }
    }
    // box1最初位于box0的右侧
    else if (max0 < min1)
    {
        if (speed >= MathType::GetValue(0))
        {
            // 投影间隔分离。
            return { true, tlast };
        }
        invSpeed = (MathType::GetValue(1)) / speed;

        t = (max0 - min1) * invSpeed;
        if (this->GetContactTime() < t)
        {
            this->SetContactTime(t);
        }

        if (tmax < this->GetContactTime())
        {
            // 间隔在指定时间内不相交。
            return { true, tlast };
        }

        t = (min0 - max1) * invSpeed;
        if (t < tlast)
        {
            tlast = t;
        }

        if (tlast < this->GetContactTime())
        {
            // 物理上不一致的时间——对象无法相交。
            return { true, tlast };
        }
    }
    // box0和box1最初重叠
    else
    {
        if (MathType::GetValue(0) < speed)
        {
            t = (max0 - min1) / speed;
            if (t < tlast)
            {
                tlast = t;
            }

            if (tlast < this->GetContactTime())
            {
                // 物理上不一致的时间——对象无法相交。
                return { true, tlast };
            }
        }
        else if (speed < MathType::GetValue(0))
        {
            t = (min0 - max1) / speed;
            if (t < tlast)
            {
                tlast = t;
            }

            if (tlast < this->GetContactTime())
            {
                // 物理上不一致的时间——对象无法相交。
                return { true, tlast };
            }
        }
    }

    return { false, tlast };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H