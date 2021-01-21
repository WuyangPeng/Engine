// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorPlane3Ellipsoid3.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::StaticTestIntersectorPlane3Ellipsoid3(const Plane3& plane, const Ellipsoid3& ellipsoid, const Real epsilon)
    : m_Plane{ plane }, m_Ellipsoid{ ellipsoid }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>
	::GetPlane() const
{
    return m_Plane;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>
	::GetEllipsoid() const
{
    return m_Ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>
	::Test()
{
	auto MInverse = m_Ellipsoid.GetMatrixInverse();
	auto discr = MInverse.QuadraticForm(m_Plane.GetNormal(), m_Plane.GetNormal());
	auto root = Math::Sqrt(Math::FAbs(discr));
	auto sDist = m_Plane.DistanceTo(m_Ellipsoid.GetCenter());
    if (Math::FAbs(sDist) <= root)
	{
		this->SetIntersectionType(IntersectionType::Other);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>
	::EllipsoidIsCulled() const
{
	auto MInverse = m_Ellipsoid.GetMatrixInverse();
    
	auto discr = MInverse.QuadraticForm(m_Plane.GetNormal(), m_Plane.GetNormal());
	auto root = Math::Sqrt(Math::FAbs(discr));
	auto sDist = m_Plane.DistanceTo(m_Ellipsoid.GetCenter());
    return sDist <= -root;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H