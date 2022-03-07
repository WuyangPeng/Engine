///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 16:57)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H

#include "Int64Vector.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>::Int64Vector() noexcept
    : tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>::Int64Vector(int64_t x, int64_t y) noexcept
    : tuple{ x, y }
{
    static_assert(VectorSize == 2);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>::Int64Vector(int64_t x, int64_t y, int64_t z) noexcept
    : tuple{ x, y, z }
{
    static_assert(VectorSize == 3);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int VectorSize>
bool Mathematics::Int64Vector<VectorSize>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int VectorSize>
const int64_t& Mathematics::Int64Vector<VectorSize>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tuple.at(index);
}

template <int VectorSize>
int64_t& Mathematics::Int64Vector<VectorSize>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(int64_t, index);
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize> Mathematics::Int64Vector<VectorSize>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Int64Vector<VectorSize> negative{};
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

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>::operator+=(const Int64Vector& rhs) noexcept
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

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>::operator-=(const Int64Vector& rhs) noexcept
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

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>::operator*=(const int64_t& scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < VectorSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        tuple[i] *= scalar;

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>::operator/=(const int64_t& scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (scalar == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除数不能为零\n"s));
    }

    for (auto i = 0; i < VectorSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        tuple[i] /= scalar;

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <int VectorSize>
int64_t Mathematics::Int64Vector<VectorSize>::SquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    int64_t squaredLength{ 0 };
    for (auto value : tuple)
    {
        squaredLength += value * value;
    }
    return squaredLength;
}

template <int VectorSize>
bool Mathematics::operator==(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs)
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

template <int VectorSize>
bool Mathematics::operator<(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs)
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

template <int VectorSize>
int64_t Mathematics::Dot(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs)
{
    int64_t dot{ 0 };
    for (auto i = 0; i < VectorSize; ++i)
    {
        dot += lhs[i] * rhs[i];
    }
    return dot;
}

template <int VectorSize>
std::ostream& Mathematics::operator<<(std::ostream& os, const Int64Vector<VectorSize>& rhs)
{
    for (auto i = 0; i < VectorSize; ++i)
    {
        os << rhs[i] << " ";
    }

    return os;
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H
