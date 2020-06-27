// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 10:19)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H

#include "RationalVector3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int IntSize>
Mathematics::RationalVector3<IntSize>
	::RationalVector3()
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>
	::RationalVector3(const RationalVector<3, IntSize>& rhs)
	:m_Tuple{ rhs }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>
	::RationalVector3(const Rational& x, const Rational& y, const Rational& z)
	:m_Tuple{}
{
	m_Tuple[0] = x;
	m_Tuple[1] = y;
	m_Tuple[2] = z;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>
	::operator= (const RationalVector<3, IntSize>& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = rhs;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int IntSize>
bool Mathematics::RationalVector3<IntSize>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int IntSize>
typename const Mathematics::RationalVector3<IntSize>::Rational	Mathematics::RationalVector3<IntSize>
	::GetX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>
	::SetX(const Rational& x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

template <int IntSize>
typename const Mathematics::RationalVector3<IntSize>::Rational	Mathematics::RationalVector3<IntSize>
	::GetY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>
	::SetY(const Rational& y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

template <int IntSize>
typename const Mathematics::RationalVector3<IntSize>::Rational	Mathematics::RationalVector3<IntSize>
	::GetZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>
	::SetZ(const Rational& z)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = z;
}

template <int IntSize>
const Mathematics::RationalVector3<IntSize>	Mathematics::RationalVector3<IntSize>
	::operator- () const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return RationalVector3(-m_Tuple);
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>&	Mathematics::RationalVector3<IntSize>
	::operator+= (const RationalVector3& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple += rhs.m_Tuple;

	return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>&	Mathematics::RationalVector3<IntSize>
	::operator-= (const RationalVector3& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple -= rhs.m_Tuple;

	return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>&	Mathematics::RationalVector3<IntSize>
	::operator*= (const Rational& rational)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple *= rational;

	return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>&	Mathematics::RationalVector3<IntSize>
	::operator/= (const Rational& rational)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple /= rational;

	return *this;
}

template <int IntSize>
typename const Mathematics::RationalVector3<IntSize>::Rational	Mathematics::RationalVector3<IntSize>
	::SquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple.SquaredLength();
}

template <int IntSize>
const Mathematics::SignRational<IntSize> Mathematics
	::Dot(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
	return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <int IntSize>
const Mathematics::RationalVector3<IntSize>	Mathematics
	::Cross(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
	return RationalVector3<IntSize>{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
									 lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
									 lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX()};
}

template <int IntSize>
const Mathematics::SignRational<IntSize> Mathematics
	::TripleScalar(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& mhs, const RationalVector3<IntSize>& rhs)
{
	return Dot(lhs, Cross(mhs, rhs));
}

template <int IntSize>
bool Mathematics
	::operator== (const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
	return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ();
}

template <int IntSize>
bool Mathematics
	::operator<  (const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
	if (lhs.GetX() < rhs.GetX())
		return true;
	else if (rhs.GetX() < lhs.GetX())
		return false;
	else if (lhs.GetY() < rhs.GetY())
		return true;
	else if (rhs.GetY() < lhs.GetY())
		return false;
	else if (lhs.GetZ() < rhs.GetZ())
		return true;
	else
		return false;
}

template <int IntSize>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const RationalVector3<IntSize>& rhs)
{
	os << "x = " << rhs.GetX() << " y = " << rhs.GetY() << " z = " << rhs.GetZ();

	return os;
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H

