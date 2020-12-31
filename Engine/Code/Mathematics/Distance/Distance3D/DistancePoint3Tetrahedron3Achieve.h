///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 16:29)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_ACHIEVE_H

#include "DistancePoint3Tetrahedron3.h"
#include "DistancePoint3Triangle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Plane3.h"

template <typename Real>
Mathematics::DistancePoint3Tetrahedron3<Real>::DistancePoint3Tetrahedron3(const Vector3D& point, const Tetrahedron3& tetrahedron) noexcept
    : ParentType{}, m_Point{ point }, m_Tetrahedron{ tetrahedron }
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
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Tetrahedron3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::DistancePoint3Tetrahedron3<Real>::GetTetrahedron() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Tetrahedron;
}

template <typename Real>
typename const Mathematics::DistancePoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistancePoint3Tetrahedron3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 为四面体的面构造平面。 法线是外部指向，但未指定为单位长度。
    /// 我们只需要知道查询点的侧面，因此可以通过不计算单位长度的法线来节省周期。
    auto planes = m_Tetrahedron.GetPlanes();

    /// 确定哪些面对查询点可见。 点到三角形的距离查询只需要处理这些。
    auto minSqrDistance = Math::sm_MaxReal;
    auto minTetraClosest = Vector3D::GetZero();
    constexpr auto tetrahedronSize = 4;
    for (auto i = 0; i < tetrahedronSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        if (planes[i].WhichSide(m_Point) != NumericalValueSymbol::Negative)
        {
            auto indices = m_Tetrahedron.GetFaceIndices(i);
            Triangle3<Real> triangle{ m_Tetrahedron.GetVertex(indices[0]), m_Tetrahedron.GetVertex(indices[1]), m_Tetrahedron.GetVertex(indices[2]) };

            DistancePoint3Triangle3<Real> query{ m_Point, triangle };
            auto sqrDistance = query.GetSquared();
            if (sqrDistance.GetDistance() < minSqrDistance)
            {
                minSqrDistance = sqrDistance.GetDistance();
                minTetraClosest = sqrDistance.GetLhsClosestPoint();
            }
        }
#include STSTEM_WARNING_POP
    }

    Vector3D closestPoint{};
    if (Math::Approximate(minSqrDistance, Math::sm_MaxReal))
    {
        // 查询点在“实心”四面体之外。
        closestPoint = minTetraClosest;
    }
    else
    {
        // 查询点在“实心”四面体内部。 返回零距离。 最接近的点是相同的。
        minSqrDistance = Math::GetValue(0);
        closestPoint = m_Point;
    }

    return DistanceResult{ minSqrDistance, Math::GetValue(0), m_Point, closestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Tetrahedron3<Real>::DistanceResult Mathematics::DistancePoint3Tetrahedron3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedTetrahedron = m_Tetrahedron.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedTetrahedron };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_ACHIEVE_H