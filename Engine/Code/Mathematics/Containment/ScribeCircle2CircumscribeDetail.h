// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 17:28)

#ifndef MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H
#define MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H

#include "ScribeCircle2Circumscribe.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ScribeCircle2Circumscribe<Real>
	::ScribeCircle2Circumscribe( const Vector2D& v0, const Vector2D& v1, const Vector2D& v2 )
	:m_Points{ v0,v1,v2 }, m_Circle2{}, m_IsCircleConstructed{ false }
{ 

	Calculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::ScribeCircle2Circumscribe<Real>
	::Calculate()
{
	auto e10 = m_Points[1] - m_Points[0];
	auto e20 = m_Points[2] - m_Points[0];

	Real matrix[2][2]  
	{
		{ e10[0], e10[1] },
		{ e20[0], e20[1] }
	};

	Real inputVector[2]  
	{
		 Math::GetRational(1,2) * Vector2DTools<Real>::VectorMagnitudeSquared(e10), 
		 Math::GetRational(1,2) * Vector2DTools<Real>::VectorMagnitudeSquared(e20),
	};

	try
	{
		Real outputVector[2]   { Math<Real>::GetValue(0) ,Math<Real>::GetValue(0) };

		LinearSystem<Real> linearSystem;

		linearSystem.Solve2(matrix,inputVector,outputVector);

		Vector2D solution{ outputVector[0],outputVector[1] };
		auto center = m_Points[0] + solution;
		auto radius = Vector2DTools<Real>::VectorMagnitude(solution);

		m_Circle2.SetCircle(center,radius);
		m_IsCircleConstructed = true;
	}
	catch (CoreTools::Error&)
	{
		m_Circle2 = Circle2();
		m_IsCircleConstructed = false;
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ScribeCircle2Circumscribe<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ScribeCircle2Circumscribe<Real>
	::IsCircleConstructed() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IsCircleConstructed;
}

template <typename Real>
const typename Mathematics::ScribeCircle2Circumscribe<Real>::Circle2 Mathematics::ScribeCircle2Circumscribe<Real>
	::GetCircle2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if(m_IsCircleConstructed)
	{
		return m_Circle2;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("输入点是线性相关的！"));
	}
}

#endif // MATHEMATICS_CONTAINMENT_SCRIBE_CIRCLE2_CIRCUMSCRIBE_DETAIL_H
 