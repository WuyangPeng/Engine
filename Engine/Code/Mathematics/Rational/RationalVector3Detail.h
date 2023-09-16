///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:14)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H

#include "RationalVector3.h"
#include "RationalVectorDetail.h"
#include "SignRationalDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <int IntSize>
Mathematics::RationalVector3<IntSize>::RationalVector3() noexcept
    : tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>::RationalVector3(const RationalVector& rhs) noexcept
    : tuple{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>::RationalVector3(const Rational& x, const Rational& y, const Rational& z) noexcept
    : tuple{ x, y, z }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>::operator=(const RationalVector& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple = rhs;

    return *this;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <int IntSize>
bool Mathematics::RationalVector3<IntSize>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int IntSize>
typename Mathematics::RationalVector3<IntSize>::Rational Mathematics::RationalVector3<IntSize>::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[0];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>::SetX(const Rational& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[0] = x;
}

template <int IntSize>
typename Mathematics::RationalVector3<IntSize>::Rational Mathematics::RationalVector3<IntSize>::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[1];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>::SetY(const Rational& y)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[1] = y;
}

template <int IntSize>
typename Mathematics::RationalVector3<IntSize>::Rational Mathematics::RationalVector3<IntSize>::GetZ() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[2];
}

template <int IntSize>
void Mathematics::RationalVector3<IntSize>::SetZ(const Rational& z)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[2] = z;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize> Mathematics::RationalVector3<IntSize>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RationalVector3{ -tuple };
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>::operator+=(const RationalVector3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple += rhs.tuple;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>::operator-=(const RationalVector3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple -= rhs.tuple;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>::operator*=(const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple *= rational;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector3<IntSize>& Mathematics::RationalVector3<IntSize>::operator/=(const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple /= rational;

    return *this;
}

template <int IntSize>
typename Mathematics::RationalVector3<IntSize>::Rational Mathematics::RationalVector3<IntSize>::SquaredLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple.SquaredLength();
}

template <int IntSize>
Mathematics::SignRational<IntSize> Mathematics::Dot(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <int IntSize>
Mathematics::RationalVector3<IntSize> Mathematics::Cross(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
    return RationalVector3<IntSize>{ lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                                     lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                                     lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <int IntSize>
Mathematics::SignRational<IntSize> Mathematics::TripleScalar(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& mhs, const RationalVector3<IntSize>& rhs)
{
    return Dot(lhs, Cross(mhs, rhs));
}

template <int IntSize>
bool Mathematics::operator==(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
{
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ();
}

template <int IntSize>
bool Mathematics::operator<(const RationalVector3<IntSize>& lhs, const RationalVector3<IntSize>& rhs)
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
std::ostream& Mathematics::operator<<(std::ostream& os, const RationalVector3<IntSize>& rhs)
{
    os << "x = " << rhs.GetX() << " y = " << rhs.GetY() << " z = " << rhs.GetZ();

    return os;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR3_DETAIL_H
