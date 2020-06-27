// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_DETAIL_H

#include "StaticFindIntersectorRay3Plane3.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::StaticFindIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane,const Real epsilon) 
	:ParentType{ epsilon }, m_Ray{ ray }, m_Plane{ plane }, m_RayParameter{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::~StaticFindIntersectorRay3Plane3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::GetPlane() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Plane;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::Find() 
{
	Line3<Real> line{ m_Ray.GetOrigin(), m_Ray.GetDirection() };
	StaticFindIntersectorLine3Plane3<Real> intr{ line, m_Plane };
	m_RayParameter = intr.GetLineParameter();
	if (intr.IsIntersection() && m_RayParameter >= Math<Real>::sm_Zero)
	{
		// The line intersects the plane, but possibly at a point that is
		// not on the ray.
		this->SetIntersectionType(intr.GetIntersectionType());
		
		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Plane3<Real>
	::GetRayParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	 
    return m_RayParameter;
}
 
#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_DETAIL_H