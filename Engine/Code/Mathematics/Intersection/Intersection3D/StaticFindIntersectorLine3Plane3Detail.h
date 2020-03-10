// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:39)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_DETAIL_H

#include "StaticFindIntersectorLine3Plane3.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::StaticFindIntersectorLine3Plane3(const Line3& line, const Plane3& plane,const Real epsilon) 
	:ParentType{ epsilon }, m_Line{ line },m_Plane{ plane }, m_LineParameter{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::~StaticFindIntersectorLine3Plane3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Plane3<Real>
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
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::GetPlane() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Plane;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::Find() 
{
	auto DdN = Vector3DTools::DotProduct(m_Line.GetDirection(),m_Plane.GetNormal());
	auto signedDistance = m_Plane.DistanceTo(m_Line.GetOrigin());
	if (Math::FAbs(DdN) > Math::sm_ZeroTolerance)
	{
		// The line is not parallel to the plane, so they must intersect.
		m_LineParameter = -signedDistance / DdN;
		 
		this->SetIntersectionType(IntersectionType::Point);
		return;
	}

	// The Line and plane are parallel.  Determine if they are numerically
	// close enough to be coincident.
	if (Math::FAbs(signedDistance) <= Math::sm_ZeroTolerance)
	{
		// The line is coincident with the plane, so choose t = 0 for the
		// parameter.
		m_LineParameter = Real{};
		this->SetIntersectionType(IntersectionType::Line);
 
		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Plane3<Real>
	::GetLineParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	 
	return m_LineParameter;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_DETAIL_H