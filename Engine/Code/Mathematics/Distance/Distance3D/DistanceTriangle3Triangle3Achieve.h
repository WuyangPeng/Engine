///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 16:59)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_ACHIEVE_H

#include "DistanceSegment3Triangle3.h"
#include "DistanceTriangle3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceTriangle3Triangle3<Real>::DistanceTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle) noexcept
    : ParentType{}, m_LhsTriangle{ lhsTriangle }, m_RhsTriangle{ rhsTriangle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Triangle3<Real>::GetLhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsTriangle;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Triangle3<Real>::GetRhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsTriangle;
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0;
    Vector3D closestPoint1;

    auto sqrDist = Math::sm_MaxReal;

    // 比较三角形0的边缘与三角形1的内部。
    auto ratio = Math::GetValue(0);

    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        auto center = (Math::GetRational(1, 2)) * (m_LhsTriangle.GetVertex(i0) + m_LhsTriangle.GetVertex(i1));
        auto direction = m_LhsTriangle.GetVertex(i1) - m_LhsTriangle.GetVertex(i0);
        auto extent = (Math::GetRational(1, 2)) * Vector3DTools::VectorMagnitude(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, m_RhsTriangle };
        auto squared = distanceSegment3Triangle3.GetSquared();
        if (squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            ratio = squared.GetLhsParameter() / edge.GetExtent();
            m_TriangleBary0[i0] = (Math::GetRational(1, 2)) * (Math::GetValue(1) - ratio);
            m_TriangleBary0[i1] = Math::GetValue(1) - m_TriangleBary0[i0];
            m_TriangleBary0[3 - i0 - i1] = Math::GetValue(0);
            m_TriangleBary1[0] = distanceSegment3Triangle3.GetTriangleBary(0);
            m_TriangleBary1[1] = distanceSegment3Triangle3.GetTriangleBary(1);
            m_TriangleBary1[2] = distanceSegment3Triangle3.GetTriangleBary(2);

            if (sqrDist <= Math::GetZeroTolerance())
            {
                DistanceResult{ Math::GetValue(0), Math::GetValue(0), closestPoint0, closestPoint1 };
            }
        }
    }

    // 将三角形1的边缘与三角形0的内部进行比较。
    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        auto center = (Math::GetRational(1, 2)) * (m_RhsTriangle.GetVertex(i0) + m_RhsTriangle.GetVertex(i1));
        auto direction = m_RhsTriangle.GetVertex(i1) - m_RhsTriangle.GetVertex(i0);
        auto extent = (Math::GetRational(1, 2)) * Vector3DTools::VectorMagnitude(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, m_LhsTriangle };
        auto squared = distanceSegment3Triangle3.GetSquared();
        if (squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            ratio = squared.GetLhsParameter() / edge.GetExtent();
            m_TriangleBary1[i0] = (Math::GetRational(1, 2)) * (Math::GetValue(1) - ratio);
            m_TriangleBary1[i1] = Math::GetValue(1) - m_TriangleBary1[i0];
            m_TriangleBary1[3 - i0 - i1] = Math::GetValue(0);
            m_TriangleBary0[0] = distanceSegment3Triangle3.GetTriangleBary(0);
            m_TriangleBary0[1] = distanceSegment3Triangle3.GetTriangleBary(1);
            m_TriangleBary0[2] = distanceSegment3Triangle3.GetTriangleBary(2);

            if (sqrDist <= Math::GetZeroTolerance())
            {
                return DistanceResult{ Math::GetValue(0), Math::GetValue(0), closestPoint0, closestPoint1 };
            }
        }
    }

    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLhsTriangle = m_LhsTriangle.GetMove(t, lhsVelocity);
    const auto movedRhsTriangle = m_RhsTriangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLhsTriangle, movedRhsTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>::GetTriangleBary0(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary0[index];
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>::GetTriangleBary1(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary1[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_ACHIEVE_H
