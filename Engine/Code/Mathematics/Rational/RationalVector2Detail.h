// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 14:43)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H

#include "RationalVector2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

template <int IntSize>
Mathematics::RationalVector2<IntSize>
	::RationalVector2()
	:m_Tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>
	::RationalVector2 (const RationalVector<2,IntSize>& rhs)
	:m_Tuple{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>
	::RationalVector2 (const Rational& x, const Rational& y)
	:m_Tuple{}
{
    m_Tuple[0] = x;
	m_Tuple[1] = y;
    
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>&	Mathematics::RationalVector2<IntSize>
	::operator= (const RationalVector<2,IntSize>& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple = rhs;
    
    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int IntSize>
bool Mathematics::RationalVector2<IntSize>
	::IsValid() const noexcept
{
    return true;   
}
#endif // OPEN_CLASS_INVARIANT

template <int IntSize>
typename const Mathematics::RationalVector2<IntSize>::Rational	Mathematics::RationalVector2<IntSize>
	::GetX () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Tuple[0];
}

template <int IntSize>
void Mathematics::RationalVector2<IntSize>
	::SetX (const Rational& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple[0] = x;
}

template <int IntSize>
typename const Mathematics::RationalVector2<IntSize>::Rational	Mathematics::RationalVector2<IntSize>
	::GetY () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Tuple[1];
}

template <int IntSize>
void Mathematics::RationalVector2<IntSize>
	::SetY (const Rational& y)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple[1] = y;
}

template <int IntSize>
const Mathematics::RationalVector2<IntSize>	Mathematics::RationalVector2<IntSize>
	::operator- () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return RationalVector2(-m_Tuple);
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>&	Mathematics::RationalVector2<IntSize>
	::operator+= (const RationalVector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple += rhs.m_Tuple;
    
    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>&	Mathematics::RationalVector2<IntSize>
	::operator-= (const RationalVector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple -= rhs.m_Tuple;
    
    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>&	Mathematics::RationalVector2<IntSize>
	::operator*= (const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple *= rational;
    
    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>&	Mathematics::RationalVector2<IntSize>
	::operator/= (const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    
    m_Tuple /= rational;
    
    return *this;
}

// Returns (y,-x).
template <int IntSize>
const Mathematics::RationalVector2<IntSize>	Mathematics::RationalVector2<IntSize>
	::Perp () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return RationalVector2(m_Tuple[1], -m_Tuple[0]);
}

template <int IntSize>
typename const Mathematics::RationalVector2<IntSize>::Rational	Mathematics::RationalVector2<IntSize>
	::SquaredLength () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
    return m_Tuple.SquaredLength ();
}

template <int IntSize>
const Mathematics::SignRational<IntSize> Mathematics
	::Dot (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs)
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY();
}


template <int IntSize>
const Mathematics::SignRational<IntSize> Mathematics
	::DotPerp (const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs)
{
     return lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX();
}

template <int IntSize>
bool Mathematics
	::operator== (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs)
{
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY();
}

template <int IntSize>
bool Mathematics
	::operator<  (const RationalVector2<IntSize>& lhs,const RationalVector2<IntSize>& rhs)
{
    if(lhs.GetX() < rhs.GetX())
        return true;
    else if(rhs.GetX() < lhs.GetX())
        return false;
    else if(lhs.GetY() < rhs.GetY())
        return true;
    else
        return false;
}


template <int IntSize>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const RationalVector2<IntSize>& rhs) 
{
	os << "x = " << rhs.GetX() << " y = " << rhs.GetY();

	return os;
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H


