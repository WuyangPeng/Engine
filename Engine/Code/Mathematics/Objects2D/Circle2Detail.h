// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 16:52)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H

#include "Circle2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Circle2<Real>
	::Circle2(const Vector2D& center, Real radius)
	:m_Center{ center }, m_Radius{ radius }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Circle2<Real>
	::Circle2()
	:m_Center{}, m_Radius{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Circle2<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::GetValue(0) <= m_Radius)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Circle2<Real>::Vector2D Mathematics::Circle2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
void Mathematics::Circle2<Real>
	::SetCircle(const Vector2D& center, Real radius)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Center = center;
	m_Radius = radius;
}

template <typename Real>
Real Mathematics::Circle2<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
bool Mathematics
	::Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& out, const Circle2<Real>& circle2)
{
	out << "center=(" << circle2.GetCenter() << "),radius=" << circle2.GetRadius();

	return out;
}

#endif // MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H