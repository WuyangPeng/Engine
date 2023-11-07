///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:34)

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

    /// Ϊ��������湹��ƽ�档 �������ⲿָ�򣬵�δָ��Ϊ��λ���ȡ�
    /// ����ֻ��Ҫ֪����ѯ��Ĳ��棬��˿���ͨ�������㵥λ���ȵķ�������ʡ���ڡ�
    auto planes = tetrahedron.GetPlanes();

    /// ȷ����Щ��Բ�ѯ��ɼ��� �㵽�����εľ����ѯֻ��Ҫ������Щ��
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
        // ��ѯ���ڡ�ʵ�ġ�������֮�⡣
        closestPoint = minTetraClosest;
    }
    else
    {
        // ��ѯ���ڡ�ʵ�ġ��������ڲ��� ��������롣 ��ӽ��ĵ�����ͬ�ġ�
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