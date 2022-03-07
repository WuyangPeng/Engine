///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 17:12)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H

#include "RationalVector.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>::RationalVector() noexcept
    : tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>::RationalVector(Rational x, Rational y) noexcept
    : tuple{ x, y }
{
    static_assert(VectorSize == 2);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>::RationalVector(Rational x, Rational y, Rational z) noexcept
    : tuple{ x, y, z }
{
    static_assert(VectorSize == 3);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int VectorSize, int IntSize>
bool Mathematics::RationalVector<VectorSize, IntSize>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int VectorSize, int IntSize>
typename const Mathematics::RationalVector<VectorSize, IntSize>::Rational& Mathematics::RationalVector<VectorSize, IntSize>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple.at(index);
}

template <int VectorSize, int IntSize>
typename Mathematics::RationalVector<VectorSize, IntSize>::Rational& Mathematics::RationalVector<VectorSize, IntSize>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Rational, index);
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize> Mathematics::RationalVector<VectorSize, IntSize>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    RationalVector negative{};
    for (auto i = 0; i < VectorSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        negative.tuple[i] = -tuple[i];

#include STSTEM_WARNING_POP
    }
    return negative;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>::operator+=(const RationalVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < VectorSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        tuple[i] += rhs.tuple[i];

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>::operator-=(const RationalVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < VectorSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        tuple[i] -= rhs.tuple[i];

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>::operator*=(const Rational& scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto& value : tuple)
    {
        value *= scalar;
    }

    return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>::operator/=(const Rational& scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto& value : tuple)
    {
        value /= scalar;
    }

    return *this;
}

template <int VectorSize, int IntSize>
typename Mathematics::RationalVector<VectorSize, IntSize>::Rational Mathematics::RationalVector<VectorSize, IntSize>::SquaredLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Rational squaredLength{ 0 };
    for (const auto& value : tuple)
    {
        squaredLength += value * value;
    }

    return squaredLength;
}

template <int VectorSize, int IntSize>
Mathematics::SignRational<IntSize> Mathematics::Dot(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
    SignRational<IntSize> dot{ 0 };
    for (auto i = 0; i < VectorSize; ++i)
    {
        dot += lhs[i] * rhs[i];
    }

    return dot;
}

template <int VectorSize, int IntSize>
bool Mathematics::operator==(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
    for (auto i = 0; i < VectorSize; ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}

template <int VectorSize, int IntSize>
bool Mathematics::operator<(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
    for (auto i = 0; i < VectorSize; ++i)
    {
        if (lhs[i] < rhs[i])
        {
            return true;
        }
        else if (rhs[i] < lhs[i])
        {
            return false;
        }
    }

    return false;
}

template <int VectorSize, int IntSize>
std::ostream& Mathematics::operator<<(std::ostream& os, const RationalVector<VectorSize, IntSize>& rhs)
{
    for (auto i = 0; i < VectorSize; ++i)
    {
        os << rhs[i] << " ";
    }

    return os;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H
