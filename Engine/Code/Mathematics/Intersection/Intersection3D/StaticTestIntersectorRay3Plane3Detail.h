// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:35)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H

#include "StaticTestIntersectorRay3Plane3.h"
#include "IntersectorLine3Triangle3DataDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::StaticTestIntersectorRay3Plane3(const Ray3& ray,const Plane3& plane,const Real epsilon) 
	:ParentType{ epsilon }, m_Ray{ ray }, m_Plane{ plane }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::~StaticTestIntersectorRay3Plane3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else		
		return false;		
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Ray;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::GetPlane() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Plane;
} 

// private
template <typename Real>
void Mathematics::StaticTestIntersectorRay3Plane3<Real>
	::Test() 
{
	Line3<Real> line{ m_Ray.GetOrigin(), m_Ray.GetDirection() };
	StaticFindIntersectorLine3Plane3<Real> intr{ line, m_Plane };
	if (intr.IsIntersection() && intr.GetLineParameter() >= Math<Real>::GetValue(0))
	{
		// The line intersects the plane, but possibly at a point that is
		// not on the ray.
		this->SetIntersectionType(intr.GetIntersectionType());
		
		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
}

#endif // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H