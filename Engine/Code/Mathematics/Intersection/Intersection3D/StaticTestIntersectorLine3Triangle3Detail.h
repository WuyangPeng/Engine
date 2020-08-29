// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 13:24)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorLine3Triangle3.h"
#include "IntersectorLine3Triangle3DataDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::StaticTestIntersectorLine3Triangle3(const Line3& line, const Triangle3& triangle,const Real epsilon) 
	:ParentType{ epsilon }, m_Line{ line }, m_Triangle{ triangle }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::~StaticTestIntersectorLine3Triangle3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else		
		return false;		
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Line;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::GetTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Triangle;
} 

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine3Triangle3<Real>
	::Test() 
{
	IntersectorLine3Triangle3Data<Real> data{ m_Line,m_Triangle };

	auto directionDotNormal = data.GetDirectionDotNormal();
	auto epsilon = this->GetEpsilon();
	auto sign = NumericalValueSymbol::Zero;

	if (epsilon < directionDotNormal)
    {
        sign = NumericalValueSymbol::Positive;
    }
	else if (directionDotNormal < epsilon)
    {
        sign = NumericalValueSymbol::Negative;
        directionDotNormal = -directionDotNormal;
    }
    else
    {
		// 线和三角形是平行的,称之为“没有交集”。
		// 即使线是相交。
        return;
    }

	auto directionDotOriginCrossEdge2 =	sign * Vector3DTools::DotProduct(m_Line.GetDirection(),data.GetOriginCrossEdge2());
	if (Math::GetValue(0) <= directionDotOriginCrossEdge2)
	{
		auto directionDotEdge1CrossOrigin =	sign * Vector3DTools::DotProduct(m_Line.GetDirection(),  data.GetEdge1CrossOrigin());

		if (Math::GetValue(0) <= directionDotEdge1CrossOrigin)
		{
			if (directionDotNormal <= directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin)
			{
				this->SetIntersectionType(IntersectionType::Point);
			}
			// else: 1 < b1 + b2, 不相交
		}
		// else: b2 < 0, 不相交
	}
	// else: b1 < 0, 不相交
}

#endif // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_DETAIL_H