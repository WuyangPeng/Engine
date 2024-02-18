/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 10:57)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H

#include "Polynomial.h"
#include "PolynomialDivideDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TemplateTools/RangeIteration.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>::Polynomial(int degree)
    : coefficient(0 <= degree ? degree + 1 : 0)
{
    if (coefficient.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"s))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>::Polynomial(const ContainerType& coefficient)
    : coefficient{ coefficient }
{
    if (coefficient.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>::Polynomial(ContainerType&& coefficient) noexcept
    : coefficient{ std::move(coefficient) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Polynomial<Real>::IsValid() const noexcept
{
    if (!coefficient.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::SetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (degree < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"))
    }

    const auto coefficientSize = degree + 1;
    coefficient.resize(coefficientSize);
    coefficient.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::SetCoefficients(Real value)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    std::fill(coefficient.begin(), coefficient.end(), value);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Polynomial<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 根据设计，coefficient.size() > 0。
    return boost::numeric_cast<int>(coefficient.size() - 1);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::Polynomial<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient.at(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::Polynomial<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Polynomial<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient.at(0);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Polynomial<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient.at(coefficient.size() - 1);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Polynomial<Real>::operator()(Real value) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Real result{};

    for (const auto& element : CoreTools::Reverse(coefficient))
    {
        result *= value;
        result += element;
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Polynomial<Real>::ContainerType Mathematics::Polynomial<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::SetCoefficients(const ContainerType& aCoefficient)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (aCoefficient.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s))
    }
    else
    {
        coefficient = aCoefficient;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::SetCoefficients(ContainerType&& aCoefficient)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (aCoefficient.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s))
    }
    else
    {
        coefficient = std::move(aCoefficient);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator+() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    ContainerType result{};

    for (auto element : coefficient)
    {
        result.emplace_back(-element);
    }

    return Polynomial{ std::move(result) };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Polynomial result{ rhs };

    if (GetDegree() < result.GetDegree())
    {
        coefficient.swap(result.coefficient);
    }

    for (auto i = 0u; i < result.coefficient.size(); ++i)
    {
        coefficient.at(i) += result.coefficient.at(i);
    }

    EliminateLeadingZeros(Math::GetZeroTolerance());

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*this) += (-rhs);

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = (*this) * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    coefficient.at(0) += scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    coefficient.at(0) -= scalar;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& element : coefficient)
    {
        element *= scalar;
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        for (auto& element : coefficient)
        {
            element /= scalar;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s))
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetDerivative() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (const auto degree = GetDegree();
        0 < degree)
    {
        Polynomial result{ degree - 1 };

        for (auto index = 0; index < degree; ++index)
        {
            const auto nextIndex = index + 1;

            result[index] = nextIndex * coefficient.at(nextIndex);
        }

        return result;
    }
    else
    {
        Polynomial result{ 0 };

        return result;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetInversion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    Polynomial result{ degree };
    for (auto i = 0; i <= degree; ++i)
    {
        const auto reverseIndex = degree - i;

        result[i] = coefficient.at(reverseIndex);
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetTranslation(Real t0) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // f(t) = t - t0
    Polynomial factor{ ContainerType{ -t0, Math::GetValue(1) } };
    const auto degree = GetDegree();
    Polynomial result{ ContainerType{ coefficient.at(degree) } };
    for (auto index = degree - 1; 0 <= index; --index)
    {
        result = coefficient.at(index) + factor * result;
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::EliminateLeadingZeros(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = GetCompressDegree(epsilon);

    const auto size = degree + 1;
    coefficient.resize(size);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Polynomial<Real>::Equal(const Polynomial& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient == rhs.coefficient;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Polynomial<Real>::Less(const Polynomial& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficient < rhs.coefficient;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Polynomial<Real>::MakeCompress(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = GetCompressDegree(epsilon);

    if (0 <= degree)
    {
        Polynomial result{ degree };

        result[degree] = Math::GetValue(1);
        for (auto i = 0; i < degree; ++i)
        {
            result[i] = coefficient.at(i) / coefficient.at(degree);
        }

        SetCoefficients(std::move(result.coefficient));
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Polynomial<Real>::GetCompressDegree(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto leading = GetDegree();

    for (; 0 < leading; --leading)
    {
        if (epsilon < Math::FAbs(coefficient.at(leading)))
        {
            return leading;
        }
    }

    return leading;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Polynomial<Real>::PolynomialDivide Mathematics::Polynomial<Real>::Divide(const Polynomial& divisor, Real epsilon) const
{
    const auto degree = GetDegree();
    const auto divisorDegree = divisor.GetDegree();
    const auto quotientDegree = degree - divisorDegree;

    if (0 <= quotientDegree)
    {
        Polynomial quotient{ quotientDegree };

        /// 临时存储的余数。
        Polynomial remainder{ *this };

        /// 做除法（欧几里得算法）。
        const auto inv = Math::GetValue(1) / divisor[divisorDegree];
        for (auto quotientIndex = quotientDegree; 0 <= quotientIndex; --quotientIndex)
        {
            auto divisorIndex = divisorDegree + quotientIndex;
            quotient[quotientIndex] = inv * remainder[divisorIndex];
            --divisorIndex;
            for (; quotientIndex <= divisorIndex; --divisorIndex)
            {
                remainder[divisorIndex] -= quotient[quotientIndex] * divisor[divisorIndex - quotientIndex];
            }
        }

        // 计算remainder正确的degree。
        if (1 <= divisorDegree)
        {
            auto remainderDegree = divisorDegree - 1;
            while (0 < remainderDegree && Math::FAbs(remainder[remainderDegree]) < epsilon)
            {
                --remainderDegree;
            }

            Polynomial correctRemainder{ remainderDegree };

            for (auto i = 0; i <= remainderDegree; ++i)
            {
                correctRemainder[i] = remainder[i];
            }

            return PolynomialDivide{ quotient, correctRemainder };
        }
        else
        {
            Polynomial correctRemainder{ 0 };

            return PolynomialDivide{ quotient, correctRemainder };
        }
    }
    else
    {
        Polynomial quotient{ 0 };
        Polynomial remainder{ *this };

        return PolynomialDivide{ quotient, *this };
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::GreatestCommonDivisor(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon)
{
    /// 分子应该是较大次数的多项式。
    auto a = rhs.GetDegree() <= lhs.GetDegree() ? lhs : rhs;
    auto b = rhs.GetDegree() <= lhs.GetDegree() ? rhs : lhs;

    const Polynomial<Real> zero{ typename Polynomial<Real>::ContainerType{ Math<Real>::GetValue(0) } };
    if (Approximate(a, zero, epsilon) || Approximate(b, zero, epsilon))
    {
        return (!Approximate(a, zero) ? a : zero);
    }

    /// 当使用浮点实数进行计算时，使多项式压缩保持系数的合理大小。
    a.MakeCompress(epsilon);
    b.MakeCompress(epsilon);

    for (;;)
    {
        if (const auto polynomialDivide = Divide(a, b);
            !Approximate(polynomialDivide.GetRemainder(), zero, epsilon))
        {
            /// a = q * b + r, 所以 gcd(a,b) = gcd(b, r)
            a = b;
            b = polynomialDivide.GetRemainder();
            b.MakeCompress(epsilon);
        }
        else
        {
            b.MakeCompress(epsilon);
            break;
        }
    }

    return b;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
std::vector<Mathematics::Polynomial<Real>> Mathematics::SquareFreeFactorization(const Polynomial<Real>& f)
{
    /// 在对Divide(...)的调用中，
    /// 我们知道除数正好除以分子，
    /// 所以在所有这样的调用之后 r = 0 a。
    std::vector<Polynomial<Real>> factors{};

    const auto fDerivative = f.GetDerivative();

    auto a = GreatestCommonDivisor(f, fDerivative);
    auto polynomialDivide = Divide(f, a);  // b = f / a
    auto b = polynomialDivide.GetQuotient();

    polynomialDivide = Divide(fDerivative, a);  // c = fDerivative / a
    auto c = polynomialDivide.GetQuotient();
    auto d = c - b.GetDerivative();

    do
    {
        a = GreatestCommonDivisor(b, d);
        factors.emplace_back(a);
        polynomialDivide = Divide(b, a);
        b = polynomialDivide.GetQuotient();  // q = b / a

        polynomialDivide = Divide(d, a);  // c = d / a
        c = polynomialDivide.GetQuotient();

        d = c - b.GetDerivative();

    } while (0 < b.GetDegree());

    return factors;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Approximate(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon)
{
    if (lhs.GetDegree() != rhs.GetDegree())
    {
        return false;
    }
    else
    {
        for (auto i = 0; i <= rhs.GetDegree(); ++i)
        {
            if (!Math<Real>::Approximate(lhs[i], rhs[i], epsilon))
            {
                return false;
            }
        }

        return true;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator!=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return lhs.Less(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    return !(lhs < rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Polynomial<Real> Mathematics::operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs)
{
    Polynomial<Real> result{ lhs.GetDegree() + rhs.GetDegree() };

    for (auto lhsIndex = 0; lhsIndex <= lhs.GetDegree(); ++lhsIndex)
    {
        for (auto rhsIndex = 0; rhsIndex <= rhs.GetDegree(); ++rhsIndex)
        {
            const auto index = lhsIndex + rhsIndex;
            result[index] += lhs[lhsIndex] * rhs[rhsIndex];
        }
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
