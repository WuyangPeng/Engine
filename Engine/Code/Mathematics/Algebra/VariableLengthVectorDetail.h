/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 09:20)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H

#include "VariableLengthVector.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

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

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>::VariableLengthVector(int size, int dimension)
    : VariableLengthVector{ size }
{
    MakeUnit(dimension);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

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
void Mathematics::VariableLengthVector<Real>::SetSize(int size)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (size < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("size为负数！"s));
    }

    container.resize(size);
    container.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::operator+() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    ContainerType result{};
    for (auto element : container)
    {
        result.emplace_back(-element);
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
        container.at(i) += rhs.container.at(i);
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
        container.at(i) -= rhs.container.at(i);
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableLengthVector<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto& element : container)
    {
        element *= scalar;
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
        this->operator*=(Math::GetValue(1) / scalar);
    }
    else
    {
        MATHEMATICS_ASSERTION_0(false, "除零错误！");

        MakeZero();
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableLengthVector<Real>::Length(bool robust) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Math::Sqrt(SquaredLength(robust));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableLengthVector<Real>::SquaredLength(bool robust) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (robust)
    {
        auto maxComponent = Math::FAbs(container.at(0));
        for (auto i = 1; i < GetSize(); ++i)
        {
            auto component = Math::FAbs(container.at(i));
            if (maxComponent < component)
            {
                maxComponent = component;
            }
        }

        if (Real{} < maxComponent)
        {
            const auto scaled = (*this) / maxComponent;

            return maxComponent * maxComponent * Dot(scaled, scaled);
        }
        else
        {
            return Real{};
        }
    }
    else
    {
        return Dot(*this, *this);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableLengthVector<Real>::Normalize(Real epsilon, bool robust)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (robust)
    {
        auto maxComponent = Math::FAbs(container.at(0));
        for (auto i = 1; i < GetSize(); ++i)
        {
            auto component = Math::FAbs(container.at(i));
            if (maxComponent < component)
            {
                maxComponent = component;
            }
        }

        Real length{};
        if (epsilon < maxComponent)
        {
            (*this) /= maxComponent;
            length = Math::Sqrt(Dot(*this, *this));
            (*this) /= length;
            length *= maxComponent;
        }
        else
        {
            MakeZero();
        }

        return length;
    }
    else
    {
        Real length = Math::Sqrt(Dot(*this, *this));
        if (epsilon < length)
        {
            (*this) /= length;
        }
        else
        {
            MakeZero();
        }

        return length;
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
void Mathematics::VariableLengthVector<Real>::SetContainer(const ContainerType& aContainer)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    container = aContainer;
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
requires std::is_arithmetic_v<Real>
void Mathematics::VariableLengthVector<Real>::MakeUnit(int dimension)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::fill(container.begin(), container.end(), Real{});
    if (0 <= dimension && dimension < boost::numeric_cast<int>(container.size()))
    {
        container.at(dimension) = Math::GetValue(1);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::Zero(int size)
{
    return VariableLengthVector{ size };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::VariableLengthVector<Real>::Unit(int size, int dimension)
{
    return VariableLengthVector{ size, dimension };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::VariableLengthVector<Real>::Equal(const VariableLengthVector& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetSize() != rhs.GetSize())
    {
        return false;
    }
    else
    {
        return container == rhs.container;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::VariableLengthVector<Real>::Less(const VariableLengthVector& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (GetSize() != rhs.GetSize())
    {
        return GetSize() < rhs.GetSize();
    }
    else
    {
        return container < rhs.container;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableLengthVector<Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::fill(container.begin(), container.end(), Real{});
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    return lhs.Less(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs)
{
    if (lhs.GetSize() != rhs.GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小不同！"s));
    }

    Real dotProduct{};

    for (auto i = 0; i < lhs.GetSize(); ++i)
    {
        dotProduct += lhs[i] * rhs[i];
    }

    return dotProduct;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Approximate(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs, Real epsilon)
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
requires std::is_arithmetic_v<Real>
Real Mathematics::Orthonormalize(int numInputs, std::vector<VariableLengthVector<Real>>& vector, bool robust)
{
    if (1 <= numInputs && numInputs <= vector.at(0).GetSize())
    {
        for (auto i = 1; i < numInputs; ++i)
        {
            if (vector.at(0).GetSize() != vector.at(i).GetSize())
            {
                THROW_EXCEPTION(SYSTEM_TEXT("大小不匹配。"))
            }
        }

        auto minLength = vector.at(0).Normalize(robust);
        for (auto i = 1; i < numInputs; ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                const auto dot = Dot(vector.at(i), vector.at(j));
                vector.at(i) -= vector.at(j) * dot;
            }

            const auto length = vector.at(i).Normalize(robust);
            if (length < minLength)
            {
                minLength = length;
            }
        }

        return minLength;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::ComputeExtremes(int numVectors, const std::vector<VariableLengthVector<Real>>& vector, VariableLengthVector<Real>& vectorMin, VariableLengthVector<Real>& vectorMax)
{
    if (0 < numVectors)
    {
        for (auto i = 1; i < numVectors; ++i)
        {
            if (vector.at(0).GetSize() != vector.at(i).GetSize())
            {
                THROW_EXCEPTION(SYSTEM_TEXT("大小不匹配。"))
            }
        }

        const auto size = vector.at(0).GetSize();
        vectorMin = vector.at(0);
        vectorMax = vectorMin;
        for (auto j = 1; j < numVectors; ++j)
        {
            const auto& element = vector.at(j);
            for (auto i = 0; i < size; ++i)
            {
                if (element[i] < vectorMin[i])
                {
                    vectorMin[i] = element[i];
                }
                else if (vectorMax[i] < element[i])
                {
                    vectorMax[i] = element[i];
                }
            }
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"))
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real> Mathematics::HomogeneousLift(const VariableLengthVector<Real>& vector, Real last)
{
    const auto size = vector.GetSize();

    VariableLengthVector result{ size + 1 };
    for (auto i = 0; i < size; ++i)
    {
        result[i] = vector[i];
    }
    result[size] = last;

    return result;
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::HomogeneousProject(const VariableLengthVector<Real>& vector)
{
    if (const auto size = vector.GetSize();
        1 < size)
    {
        VariableLengthVector<Real> result{ size - 1 };
        for (auto i = 0; i < size - 1; ++i)
        {
            result[i] = vector[i];
        }

        return result;
    }
    else
    {
        return VariableLengthVector<Real>{};
    }
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::Lift(const VariableLengthVector<Real>& vector, int inject, Real value)
{
    const auto size = vector.GetSize();
    VariableLengthVector<Real> result{ size + 1 };
    auto i = 0;
    for (; i < inject; ++i)
    {
        result[i] = vector[i];
    }

    result[i] = value;
    auto j = i;
    for (++j; i < size; ++i, ++j)
    {
        result[j] = vector[i];
    }

    return result;
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::Project(const VariableLengthVector<Real>& vector, int reject)
{
    if (const auto size = vector.GetSize();
        1 < size)
    {
        VariableLengthVector<Real> result{ size - 1 };
        for (auto i = 0, j = 0; i < size - 1; ++i, ++j)
        {
            if (j == reject)
            {
                ++j;
            }
            result[i] = vector[j];
        }

        return result;
    }
    else
    {
        return VariableLengthVector<Real>{};
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector)
{
    for (auto i = 0; i < vector.GetSize(); ++i)
    {
        outFile << "(" << i << ")=" << vector[i] << "　";
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_DETAIL_H
