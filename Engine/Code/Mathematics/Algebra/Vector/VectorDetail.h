/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/27 15:29)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_DETAIL_H

#include "Vector.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector() noexcept
    : container{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector(const Container& container) noexcept
    : container{ container }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector(Real x, Real y) noexcept requires(N == 2)
    : container{ x, y }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector(Real x, Real y, Real z) noexcept requires(N == 3)
    : container{ x, y, z }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector(Real x, Real y, Real z, Real w) noexcept requires(N == 4)
    : container{ x, y, z, w }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>::Vector(int direction)
    : container{}
{
    MakeUnit(direction);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
const Real& Mathematics::Algebra::Vector<N, Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real& Mathematics::Algebra::Vector<N, Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator==(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container == rhs.container;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator!=(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(*this == rhs);
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator<(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return container < rhs.container;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator<=(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(rhs < *this);
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator>(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this < rhs;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Vector<N, Real>::operator>=(const Vector& rhs) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(*this < rhs);
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Vector<N, Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::fill(container.begin(), container.end(), Real{});
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Vector<N, Real>::MakeOnes()
{
    std::fill(container.begin(), container.end(), MathType::GetValue(1));
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Vector<N, Real>::MakeUnit(int direction)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::fill(container.begin(), container.end(), Real{});
    if (0 <= direction && direction < N)
    {
        container.at(direction) = MathType::GetValue(1);
    }
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Vector<N, Real>::GetZero() noexcept
{
    return Vector{};
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Vector<N, Real>::GetOnes()
{
    Vector result{};
    result.MakeOnes();

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Vector<N, Real>::GetUnit(int direction)
{
    Vector result{};
    result.MakeUnit(direction);

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Vector<N, Real>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::Vector<N, Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector result{};
    for (auto i = 0; i < N; ++i)
    {
        result[i] = -container.at(i);
    }

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator+=(const Vector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < N; ++i)
    {
        container.at(i) += rhs[i];
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator-=(const Vector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < N; ++i)
    {
        container.at(i) -= rhs[i];
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < N; ++i)
    {
        container.at(i) *= scalar;
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!MathType::Approximate(scalar, MathType::GetZeroTolerance()))
    {
        for (auto i = 0; i < N; ++i)
        {
            container.at(i) /= scalar;
        }
    }
    else
    {
        MakeZero();

        LOG_SINGLETON_ENGINE_APPENDER(Info, Mathematics, SYSTEM_TEXT("除零错误。scalar = "), scalar, SYSTEM_TEXT(", N = "), N);
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator*=(const Vector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < N; ++i)
    {
        container.at(i) *= rhs[i];
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real>& Mathematics::Algebra::Vector<N, Real>::operator/=(const Vector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < N; ++i)
    {
        container.at(i) /= rhs[i];
    }

    return *this;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Vector<N, Real>::GetMaxComponent() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto maxComponent = MathType::FAbs(container.at(0));

    if constexpr (N == 1)
    {
        return maxComponent;
    }
    else
    {
        for (auto i = 1; i < N; ++i)
        {
            const auto component = MathType::FAbs(container.at(i));
            if (maxComponent < component)
            {
                maxComponent = component;
            }
        }

        return maxComponent;
    }
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator+(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{ lhs };

    result += rhs;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator-(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{ lhs };

    result -= rhs;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator*(const Vector<N, Real>& lhs, Real scalar)
{
    Vector<N, Real> result{ lhs };

    result *= scalar;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator*(Real scalar, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{ rhs };

    result *= scalar;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator/(const Vector<N, Real>& lhs, Real scalar)
{
    Vector<N, Real> result{ lhs };

    result /= scalar;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator*(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{ lhs };

    result *= rhs;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::operator/(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    Vector<N, Real> result{ lhs };

    result /= rhs;

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Dot(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs)
{
    auto dot = lhs[0] * rhs[0];

    for (auto i = 1; i < N; ++i)
    {
        dot += lhs[i] * rhs[i];
    }

    return dot;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Length(const Vector<N, Real>& vector, bool robust)
{
    if (robust)
    {
        const auto maxComponent = vector.GetMaxComponent();

        Real length{};
        if (Real{} < maxComponent)
        {
            const auto scaled = vector / maxComponent;

            length = maxComponent * Math<Real>::Sqrt(Dot(scaled, scaled));
        }
        else
        {
            length = Real{};
        }

        return length;
    }
    else
    {
        return Math<Real>::Sqrt(Dot(vector, vector));
    }
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Normalize(Vector<N, Real>& vector, bool robust)
{
    if (robust)
    {
        const auto maxComponent = vector.GetMaxComponent();

        if (Real{} < maxComponent)
        {
            vector /= maxComponent;
            auto length = Math<Real>::Sqrt(Dot(vector, vector));
            vector /= length;
            length *= maxComponent;

            return length;
        }
        else
        {
            vector.MakeZero();

            return Real{};
        }
    }
    else
    {
        auto length = Math<Real>::Sqrt(Dot(vector, vector));
        if (Real{} < length)
        {
            vector /= length;
        }
        else
        {
            for (auto i = 0; i < N; ++i)
            {
                vector[i] = Real{};
            }
        }

        return length;
    }
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Orthonormalize(int numInputs, std::vector<Vector<N, Real>>& vector, bool robust)
{
    if (1 <= numInputs && numInputs <= N)
    {
        auto minLength = Normalize(vector.at(0), robust);

        for (auto i = 1; i < numInputs; ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                auto dot = Dot(vector.at(i), vector.at(j));
                vector.at(i) -= vector.at(j) * dot;
            }

            const auto length = Normalize(vector.at(i), robust);
            if (length < minLength)
            {
                minLength = length;
            }
        }
        return minLength;
    }

    return Real{};
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N, Real> Mathematics::Algebra::GetOrthogonal(const Vector<N, Real>& vector, bool unitLength)
{
    auto componentMax = Math<Real>::FAbs(vector[0]);
    auto indexMax = 0;
    for (auto i = 1; i < N; ++i)
    {
        auto c = Math<Real>::FAbs(vector[i]);
        if (componentMax < c)
        {
            componentMax = c;
            indexMax = i;
        }
    }

    Vector<N, Real> result{};

    auto indexNext = indexMax + 1;
    if (indexNext == N)
    {
        indexNext = 0;
    }

    result[indexMax] = vector[indexNext];
    result[indexNext] = -vector[indexMax];
    if (unitLength)
    {
        auto sqrDistance = result[indexMax] * result[indexMax] + result[indexNext] * result[indexNext];
        auto invLength = Math<Real>::GetValue(1) / std::sqrt(sqrDistance);
        result[indexMax] *= invLength;
        result[indexNext] *= invLength;
    }

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::ComputeExtremes(int numVectors, std::vector<Vector<N, Real>>& vector, Vector<N, Real>& vectorMin, Vector<N, Real>& vectorMax)
{
    if (0 < numVectors)
    {
        vectorMin = vector.at(0);
        vectorMax = vectorMin;
        for (auto j = 1; j < numVectors; ++j)
        {
            const auto& element = vector.at(j);
            for (auto i = 0; i < N; ++i)
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

        return true;
    }

    return false;
}

template <int N, typename Real>
requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N + 1, Real> Mathematics::Algebra::HomogeneousLift(const Vector<N, Real>& vector, Real last)
{
    Vector<N + 1, Real> result{};

    for (auto i = 0; i < N; ++i)
    {
        result[i] = vector[i];
    }
    result[N] = last;

    return result;
}

template <int N, typename Real>
requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N - 1, Real> Mathematics::Algebra::HomogeneousProject(const Vector<N, Real>& vector)
{
    Vector<N - 1, Real> result{};

    for (auto i = 0; i < N - 1; ++i)
    {
        result[i] = vector[i];
    }

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N + 1, Real> Mathematics::Algebra::Lift(const Vector<N, Real>& vector, int inject, Real value)
{
    Vector<N + 1, Real> result{};
    auto i = 0;
    for (; i < inject; ++i)
    {
        result[i] = vector[i];
    }

    result[i] = value;
    auto j = i + 1;
    for (; i < N; ++i, ++j)
    {
        result[j] = vector[i];
    }

    return result;
}

template <int N, typename Real>
requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<N - 1, Real> Mathematics::Algebra::Project(const Vector<N, Real>& vector, int reject)
{
    Vector<N - 1, Real> result{};

    for (auto i = 0, j = 0; i < N - 1; ++i, ++j)
    {
        if (j == reject)
        {
            ++j;
        }

        result[i] = vector[j];
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_DETAIL_H
