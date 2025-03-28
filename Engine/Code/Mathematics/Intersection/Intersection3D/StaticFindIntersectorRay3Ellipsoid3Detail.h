///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorRay3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::StaticFindIntersectorRay3Ellipsoid3(const Ray3& ray, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, ellipsoid{ ellipsoid }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::Find()
{
    /// 椭球是(X - K)^T * M * (X - K)-1 = 0并且线是X = P + t * D。
    //  将线方程代入椭球方程以获得二次方程
    //  Q(t) = a2*t^2 + 2*a1*t + a0 = 0
    //  其中a2 = D^T * M * D, a1 = D^T * M * (P - K), 和 a0 = (P - K)^T * M * (P - K) - 1 。
    const auto matrix = ellipsoid.GetMatrix();

    auto diff = ray.GetOrigin() - ellipsoid.GetCenter();
    const auto matrixDirection = matrix * ray.GetDirection();
    const auto matrixDiff = matrix * diff;
    auto a2 = Vector3ToolsType::DotProduct(ray.GetDirection(), matrixDirection);
    auto a1 = Vector3ToolsType::DotProduct(ray.GetDirection(), matrixDiff);
    auto a0 = Vector3ToolsType::DotProduct(diff, matrixDiff) - MathType::GetValue(1);

    // 如果Q(t) 具有t >= 0的实根，则发生相交。
    auto discr = a1 * a1 - a0 * a2;

    if (discr < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
    }
    else if (MathType::GetZeroTolerance() < discr)
    {
        auto root = MathType::Sqrt(discr);
        auto inv = MathType::GetValue(1) / a2;
        auto t0 = (-a1 - root) * inv;
        auto t1 = (-a1 + root) * inv;

        if (MathType::GetValue(0) <= t0)
        {
            this->SetIntersectionType(IntersectionType::Segment);
            quantity = 2;
            point0 = ray.GetOrigin() + t0 * ray.GetDirection();
            point1 = ray.GetOrigin() + t1 * ray.GetDirection();
        }
        else if (MathType::GetValue(0) <= t1)
        {
            this->SetIntersectionType(IntersectionType::Point);
            quantity = 1;
            point0 = ray.GetOrigin() + t1 * ray.GetDirection();
            t0 = t1;
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
    }
    else
    {
        auto t0 = -a1 / a2;
        if (MathType::GetValue(0) <= t0)
        {
            this->SetIntersectionType(IntersectionType::Point);
            quantity = 1;
            point0 = ray.GetOrigin() + t0 * ray.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorRay3Ellipsoid3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H