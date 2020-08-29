// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:26)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H

#include "StaticTestIntersectorLine3Plane3.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::StaticTestIntersectorLine3Plane3(const Line3& line,const Plane3& plane, const Real epsilon) 
	:ParentType{ epsilon }, m_Line{ line }, m_Plane{ plane }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::~StaticTestIntersectorLine3Plane3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else		
		return false;		
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Line;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::GetPlane() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Plane;
} 

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine3Plane3<Real>
	::Test() 
{
	auto DdN = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Plane.GetNormal());
 
	if (Math::FAbs(DdN) > Math::GetZeroTolerance())
	{
		// The line is not parallel to the plane, so they must intersect.
		// The line parameter is *not* set, since this is a test-intersection
		// query.
		this->SetIntersectionType(IntersectionType::Point);
		return;
	}

	// The line and plane are parallel.  Determine if they are numerically
	// close enough to be coincident.
	auto signedDistance = m_Plane.DistanceTo(m_Line.GetOrigin());
	if (Math::FAbs(signedDistance) <= Math::GetZeroTolerance())
	{
		this->SetIntersectionType(IntersectionType::Line);
		return;
	}

	this->SetIntersectionType(IntersectionType::Empty);
	return;
}

#endif // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H