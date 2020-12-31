// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H

#include "StaticTestIntersectorPlane3Box3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Box3<Real>
	::StaticTestIntersectorPlane3Box3(const Plane3& plane, const Box3& box)
	: m_Plane{ plane }, m_Box{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Box3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorPlane3Box3<Real>
	::GetBox() const
{
    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Box3<Real>
	::Test()
{
    Real tmp[3] { m_Box.GetExtent(0)*(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Box.GetAxis(0))),
				  m_Box.GetExtent(1)*(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Box.GetAxis(1))),
				  m_Box.GetExtent(2)*(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Box.GetAxis(2))) };

	auto radius = Math::FAbs(tmp[0]) + Math::FAbs(tmp[1]) + Math::FAbs(tmp[2]);

	auto signedDistance = m_Plane.DistanceTo(m_Box.GetCenter());
	if (Math::FAbs(signedDistance) <= radius)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
bool  Mathematics::StaticTestIntersectorPlane3Box3<Real>
	::BoxIsCulled() const
{
    Real tmp[3] { m_Box.GetExtent(0)*(Vector3DTools::DotProduct(m_Plane.GetNormal(),m_Box.GetAxis(0))),
				  m_Box.GetExtent(1)*(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Box.GetAxis(1))),
				  m_Box.GetExtent(2)*(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Box.GetAxis(2))) };

	auto radius = Math::FAbs(tmp[0]) + Math::FAbs(tmp[1]) + Math::FAbs(tmp[2]);

	auto signedDistance = m_Plane.DistanceTo(m_Box.GetCenter());
    return signedDistance <= -radius;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H