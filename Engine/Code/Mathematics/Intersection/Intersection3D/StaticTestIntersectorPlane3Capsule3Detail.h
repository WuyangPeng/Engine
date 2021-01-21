// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorPlane3Capsule3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::StaticTestIntersectorPlane3Capsule3(const Plane3& plane, const Capsule3& capsule, const Real epsilon)
    : m_Plane{ plane }, m_Capsule{ capsule }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::GetCapsule() const
{
    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::Test()
{
	auto pDist = m_Plane.DistanceTo(m_Capsule.GetSegment().GetEndPoint());
	auto nDist = m_Plane.DistanceTo(m_Capsule.GetSegment().GetBeginPoint());
    if (pDist*nDist <= Math<Real>::GetValue(0))
    {
        // Capsule segment endpoints on opposite sides of the plane.
		this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // Endpoints on same side of plane, but the endpoint spheres (with
    // radius of the capsule) might intersect the plane.
	if (Math::FAbs(pDist) <= m_Capsule.GetRadius()|| Math::FAbs(nDist) <= m_Capsule.GetRadius())
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Capsule3<Real>
	::CapsuleIsCulled() const
{
	auto pDist = m_Plane.DistanceTo(m_Capsule.GetSegment().GetEndPoint());
    if (pDist < Math<Real>::GetValue(0))
    {
		auto nDist = m_Plane.DistanceTo(m_Capsule.GetSegment().GetBeginPoint());
        if (nDist < Math<Real>::GetValue(0))
        {
            if (pDist <= nDist)
            {
				return (pDist <= -m_Capsule.GetRadius());				
            }
            else
            {
				return (nDist <= -m_Capsule.GetRadius());
            }
        }
    }

    return false;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H