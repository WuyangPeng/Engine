///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:05)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H

#include "VariableLengthVector.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector() noexcept
    : container{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(int size)
    : container(size)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(const ContainerType& container)
    : container{ container }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(ContainerType&& container) noexcept
    : container{ std::move(container) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::VariableLengthVector<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableLengthVector<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::VariableLengthVector<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::VariableLengthVector<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableLengthVector<Real>::ResetSize(int size)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (size < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("size为负数！"s));
    }

    container.clear();
    container.resize(size);
    container.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    ContainerType result{};
    for (auto value : container)
    {
        result.emplace_back(-value);
    }

    return VariableLengthVector{ std::move(result) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator+=(const VariableLengthVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (container.size() != rhs.container.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s))
    }

    for (auto i = 0u; i < container.size(); ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        container[i] += rhs.container[i];

#include SYSTEM_WARNING_POP
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator-=(const VariableLengthVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (container.size() != rhs.container.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    for (auto i = 0u; i < container.size(); ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        container[i] -= rhs.container[i];

#include SYSTEM_WARNING_POP
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto& value : container)
    {
        value *= scalar;
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator/=(Real scalar) noexcept(gMathematicsAssert < 0)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::epsilon < Math::FAbs(scalar))
    {
        for (auto& value : container)
        {
            value /= scalar;
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "除零错误！");

        for (auto& value : container)
        {
            value = Math::maxReal;
        }
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableLengthVector<Real>::Length() const noexcept(gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableLengthVector<Real>::SquaredLength() const noexcept(gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto squaredLength = Math::GetValue(0);

    for (auto value : container)
    {
        squaredLength += value * value;
    }

    MATHEMATICS_ASSERTION_2(0 <= squaredLength, "返回值不能为负数！");

    return squaredLength;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableLengthVector<Real>::Normalize(Real epsilon) noexcept(gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto length = Length();

    if (epsilon < length)
    {
        for (auto& value : container)
        {
            value /= length;
        }
    }
    else
    {
        MATHEMATICS_ASSERTION_2(false, "零向量不能正则化！");

        for (auto& value : container)
        {
            value = Math::GetValue(0);
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableLengthVector<Real>::ContainerType Mathematics::VariableLengthVector<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableLengthVector<Real>::SetContainer(const ContainerType& newContainer)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    container = newContainer;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeConstIter Mathematics::VariableLengthVector<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container.begin();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeConstIter Mathematics::VariableLengthVector<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container.end();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeIter Mathematics::VariableLengthVector<Real>::begin() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return container.begin();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableLengthVector<Real>::ContainerTypeIter Mathematics::VariableLengthVector<Real>::end() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return container.end();
}

template <typename Real>
bool Mathematics::operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        return false;
    }
    else
    {
        return lhs.GetContainer() == rhs.GetContainer();
    }
}

template <typename Real>
bool Mathematics::operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    return lhs.GetContainer() < rhs.GetContainer();
}

template <typename Real>
Real Mathematics::Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    auto dotProduct = Math<Real>::GetValue(0);

    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        dotProduct += lhs[i] * rhs[i];
    }

    return dotProduct;
}

template <typename Real>
bool Mathematics::Approximate(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs, const Real epsilon)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        if (epsilon < Math<Real>::FAbs(lhs[i] - rhs[i]))
        {
            return false;
        }
    }

    return true;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector)
{
    for (auto i = 0; i < vector.GetSize(); ++i)
    {
        outFile << "(" << i << ")=" << vector[i] << "　";
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
