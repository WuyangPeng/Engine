///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:34)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H

#include "DistancePoint3Tetrahedron3.h"
#include "DistancePoint3Triangle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Tetrahedron3<Real>::DistancePoint3Tetrahedron3(const Vector3& point, const Tetrahedron3& tetrahedron) noexcept
    : ParentType{}, point{ point }, tetrahedron{ tetrahedron }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Tetrahedron3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Tetrahedron3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Tetrahedron3<Real> Mathematics::DistancePoint3Tetrahedron3<Real>::GetTetrahedron() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tetrahedron;
}

template <typename Real>
typename Mathematics::DistancePoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistancePoint3Tetrahedron3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 为四面体的面构造平面。 法线是外部指向，但未指定为单位长度。
    /// 我们只需要知道查询点的侧面，因此可以通过不计算单位长度的法线来节省周期。
    auto planes = tetrahedron.GetPlanes();

    /// 确定哪些面对查询点可见。 点到三角形的距离查询只需要处理这些。
    auto minSqrDistance = Math::maxReal;
    auto minTetraClosest = Vector3::GetZero();
    constexpr auto tetrahedronSize = 4;
    for (auto i = 0; i < tetrahedronSize; ++i)
    {
        if (planes.at(i).WhichSide(point) != NumericalValueSymbol::Negative)
        {
            const auto indices = tetrahedron.GetFaceIndices(i);
            const Triangle3<Real> triangle{ tetrahedron.GetVertex(indices.at(0)), tetrahedron.GetVertex(indices.at(1)), tetrahedron.GetVertex(indices.at(2)) };

            DistancePoint3Triangle3<Real> query{ point, triangle };
            const auto sqrDistance = query.GetSquared();
            if (sqrDistance.GetDistance() < minSqrDistance)
            {
                minSqrDistance = sqrDistance.GetDistance();
                minTetraClosest = sqrDistance.GetLhsClosestPoint();
            }
        }
    }

    Vector3 closestPoint{};
    if (Math::Approximate(minSqrDistance, Math::maxReal))
    {
        // 查询点在“实心”四面体之外。
        closestPoint = minTetraClosest;
    }
    else
    {
        // 查询点在“实心”四面体内部。 返回零距离。 最接近的点是相同的。
        minSqrDistance = Math::GetValue(0);
        closestPoint = point;
    }

    return DistanceResult{ minSqrDistance, Math::GetValue(0), point, closestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistancePoint3Tetrahedron3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedTetrahedron = tetrahedron.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedTetrahedron };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_DETAIL_H