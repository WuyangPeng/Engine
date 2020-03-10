// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/06 11:16)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H

#include "Arc2.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Arc2<Real>
	::Arc2( const Vector2D& center, Real radius,const Vector2D& firstEnd, const Vector2D& secondEnd,const Real epsilon )
	:m_Center{ center }, m_Radius{ radius }, m_FirstEnd{ firstEnd }, m_SecondEnd{ secondEnd }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Arc2<Real>
	::IsValid() const noexcept
{
	if(Math::Approximate(Vector2DTools::Distance(m_Center,m_FirstEnd),m_Radius, m_Epsilon) &&
	   Math::Approximate(Vector2DTools::Distance(m_Center,m_SecondEnd),m_Radius, m_Epsilon))
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
bool Mathematics::Arc2<Real>
	::Contains( const Vector2D& point ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_2(Math::Approximate(Vector2DTools::Distance(m_Center,point),m_Radius, m_Epsilon),"point不在圆上。");

	// 断言：|P-C| = Real其中P为输入点，C为圆心，Real为圆弧半径。
	// 对于P是在圆弧A至B，它必须是在包含A的平面，法线N = Perp(B-A)
	// 这里Perp(u,v) = (v,-u)。

	auto diffPointEnd0 = point - m_FirstEnd;
	auto diffEnd1End0 = m_SecondEnd - m_FirstEnd;
	auto dotPerp = Vector2DTools::DotPerp(diffPointEnd0,diffEnd1End0);

	return -m_Epsilon <= dotPerp;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
Real Mathematics::Arc2<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>
	::GetFirstEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_FirstEnd;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>
	::GetSecondEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SecondEnd;
}

template <typename Real>
bool Mathematics
	::Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenter(),rhs.GetCenter(),epsilon) &&
		   Math<Real>::Approximate(lhs.GetRadius(),rhs.GetRadius(),epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetFirstEnd(), rhs.GetFirstEnd(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetSecondEnd(), rhs.GetSecondEnd(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& out, const Arc2<Real>& arc2)
{
	out << "center=(" << arc2.GetCenter() << "),radius=" << arc2.GetRadius()
		<< ",firstEnd=(" << arc2.GetFirstEnd() << "),secondEnd=("
		<< arc2.GetSecondEnd() << ")";

	return out;
}


#endif // MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H

