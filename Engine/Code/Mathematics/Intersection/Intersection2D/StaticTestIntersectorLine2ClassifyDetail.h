// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/13 10:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_DETAIL_H

#include "StaticTestIntersectorLine2Classify.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Classify<Real>
	::StaticTestIntersectorLine2Classify(const Vector2D& lhsOrigin,const Vector2D& lhsDirection,const Vector2D& rhsOrigin, 
										 const Vector2D& rhsDirection,bool isCalculateParameter,const Real epsilon)
	:ParentType(epsilon), m_FirstParameter(Real{}),m_SecondParameter(Real{})
{
	Test(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, isCalculateParameter);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine2Classify<Real>
	::Test(const Vector2D& lhsOrigin, const Vector2D& lhsDirection,const Vector2D& rhsOrigin, const Vector2D& rhsDirection, bool isCalculateParameter)
{
    auto dotThreshold = this->GetEpsilon();

    // The intersection of two lines is a solution to P0+s0*D0 = P1+s1*D1.
    // Rewrite this as s0*D0 - s1*D1 = P1 - P0 = Q.  If D0.Dot(Perp(D1)) = 0,
    // the lines are parallel.  Additionally, if Q.Dot(Perp(D1)) = 0, the
    // lines are the same.  If D0.Dot(Perp(D1)) is not zero, then
    //   s0 = Q.Dot(Perp(D1))/D0.Dot(Perp(D1))
    // produces the point of intersection.  Also,
    //   s1 = Q.Dot(Perp(D0))/D0.Dot(Perp(D1))

	auto difference = rhsOrigin - lhsOrigin;
	auto lhsDirectionDotPerpRhsDirection = Vector2DTools::DotPerp(lhsDirection,rhsDirection);
	if (dotThreshold < Math::FAbs(lhsDirectionDotPerpRhsDirection))
    {
        // ���ڵ������ཻ��
		if (isCalculateParameter)
        {   
			auto differenceDotPerpLhsDirection = Vector2DTools::DotPerp(difference,lhsDirection);
			auto differenceDotPerpRhsDirection = Vector2DTools::DotPerp(difference,rhsDirection);
			m_FirstParameter = differenceDotPerpRhsDirection / lhsDirectionDotPerpRhsDirection;
			m_SecondParameter = differenceDotPerpLhsDirection / lhsDirectionDotPerpRhsDirection;
        }

		this->SetIntersectionType(IntersectionType::Point);
		return;
    }

    // ����ƽ�еġ�
	if (difference.IsZero(dotThreshold))
	{
		// ���ǹ��ߵ�.
		this->SetIntersectionType(IntersectionType::Line);
		return;
	}

	difference.Normalize(dotThreshold);
	auto differenceDotPerpRhsDirection = Vector2DTools::DotPerp(difference,rhsDirection);
	if (Math::FAbs(differenceDotPerpRhsDirection) <= dotThreshold)
    {
        // ���ǹ��ߵ�.
		this->SetIntersectionType(IntersectionType::Line);
    }
	else
	{
		// ����ƽ�еģ����ǲ���ͬ��
		this->SetIntersectionType(IntersectionType::Empty);
	}   
}

template <typename Real>
Mathematics::StaticTestIntersectorLine2Classify<Real>
	::~StaticTestIntersectorLine2Classify()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Classify<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT 

template <typename Real>
Real Mathematics::StaticTestIntersectorLine2Classify<Real>
	::GetFirstParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_FirstParameter;
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine2Classify<Real>
	::GetSecondParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SecondParameter;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_DETAIL_H
 