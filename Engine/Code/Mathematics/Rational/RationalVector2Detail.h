/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:20)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H

#include "RationalVector2.h"
#include "RationalVectorDetail.h"
#include "SignRationalDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int IntSize>
Mathematics::RationalVector2<IntSize>::RationalVector2() noexcept
    : tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>::RationalVector2(const RationalVector& rhs) noexcept
    : tuple{ rhs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>::RationalVector2(const Rational& x, const Rational& y) noexcept
    : tuple{ x, y }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int IntSize>
Mathematics::RationalVector2<IntSize>& Mathematics::RationalVector2<IntSize>::operator=(const RationalVector& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple = rhs;

    return *this;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <int IntSize>
bool Mathematics::RationalVector2<IntSize>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int IntSize>
typename Mathematics::RationalVector2<IntSize>::Rational Mathematics::RationalVector2<IntSize>::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[0];
}

template <int IntSize>
void Mathematics::RationalVector2<IntSize>::SetX(const Rational& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[0] = x;
}

template <int IntSize>
typename Mathematics::RationalVector2<IntSize>::Rational Mathematics::RationalVector2<IntSize>::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple[1];
}

template <int IntSize>
void Mathematics::RationalVector2<IntSize>::SetY(const Rational& y)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple[1] = y;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize> Mathematics::RationalVector2<IntSize>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RationalVector2{ -tuple };
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>& Mathematics::RationalVector2<IntSize>::operator+=(const RationalVector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple += rhs.tuple;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>& Mathematics::RationalVector2<IntSize>::operator-=(const RationalVector2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple -= rhs.tuple;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>& Mathematics::RationalVector2<IntSize>::operator*=(const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple *= rational;

    return *this;
}

template <int IntSize>
Mathematics::RationalVector2<IntSize>& Mathematics::RationalVector2<IntSize>::operator/=(const Rational& rational)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple /= rational;

    return *this;
}

// Returns (y,-x).
template <int IntSize>
Mathematics::RationalVector2<IntSize> Mathematics::RationalVector2<IntSize>::Perp() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return RationalVector2{ tuple[1], -tuple[0] };
}

template <int IntSize>
typename Mathematics::RationalVector2<IntSize>::Rational Mathematics::RationalVector2<IntSize>::SquaredLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple.SquaredLength();
}

template <int IntSize>
Mathematics::SignRational<IntSize> Mathematics::Dot(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs)
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY();
}

template <int IntSize>
Mathematics::SignRational<IntSize> Mathematics::DotPerp(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs)
{
    return lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX();
}

template <int IntSize>
bool Mathematics::operator==(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs)
{
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY();
}

template <int IntSize>
bool Mathematics::operator<(const RationalVector2<IntSize>& lhs, const RationalVector2<IntSize>& rhs)
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else
        return false;
}

template <int IntSize>
std::ostream& Mathematics::operator<<(std::ostream& os, const RationalVector2<IntSize>& rhs)
{
    os << "x = " << rhs.GetX() << " y = " << rhs.GetY();

    return os;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR2_DETAIL_H
