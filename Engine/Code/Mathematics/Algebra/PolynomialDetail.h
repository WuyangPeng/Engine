///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 14:28)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DETAIL_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TemplateTools/RangeIteration.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(int degree)
    : coeff(0 <= degree ? degree + 1 : 0)
{
    if (coeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const ContainerType& coeff)
    : coeff{ coeff }
{
    if (coeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(ContainerType&& coeff)
    : coeff{ coeff }
{
    if (coeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Polynomial<Real>::IsValid() const noexcept
{
    if (!coeff.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Polynomial<Real>::ResetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (degree < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"));
    }

    coeff.clear();

    const auto coeffSize = degree + 1;
    coeff.resize(coeffSize);
    coeff.shrink_to_fit();
}

template <typename Real>
int Mathematics::Polynomial<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(coeff.size() - 1);
}

template <typename Real>
const Real& Mathematics::Polynomial<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coeff.at(index);
}

template <typename Real>
Real& Mathematics::Polynomial<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return coeff[0];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return coeff[coeff.size() - 1];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Polynomial<Real>::operator()(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Real result{};

    for (auto& number : CoreTools::Reverse(coeff))
    {
        result *= value;
        result += number;
    }

    return result;
}

template <typename Real>
typename Mathematics::Polynomial<Real>::ContainerType Mathematics::Polynomial<Real>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coeff;
}

template <typename Real>
void Mathematics::Polynomial<Real>::SetValue(const ContainerType& newCoeff)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (newCoeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }
    else
    {
        coeff = newCoeff;
    }
}

template <typename Real>
void Mathematics::Polynomial<Real>::SetValue(ContainerType&& newCoeff)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (newCoeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }
    else
    {
        coeff = std::move(newCoeff);
    }
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    ContainerType result{};

    for (auto value : coeff)
    {
        result.emplace_back(-value);
    }

    return Polynomial<Real>{ std::move(result) };
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    Polynomial result{ rhs };

    if (GetDegree() < result.GetDegree())
    {
        coeff.swap(result.coeff);
    }

    for (auto i = 0u; i < result.coeff.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        coeff[i] += result.coeff[i];

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*this) += (-rhs);

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    *this = (*this) * rhs;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    coeff[0] += scalar;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    coeff[0] -= scalar;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& value : coeff)
    {
        value *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        for (auto& value : coeff)
        {
            value /= scalar;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetDerivative() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    if (0 < degree)
    {
        Polynomial result{ degree - 1 };

        for (auto index = 0; index < degree; ++index)
        {
            const auto nextIndex = index + 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            result[index] = nextIndex * coeff[nextIndex];

#include STSTEM_WARNING_POP
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
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetInversion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    Polynomial result{ degree };
    for (auto i = 0; i <= degree; ++i)
    {
        const auto reverseIndex = degree - i;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        result[i] = coeff[reverseIndex];

#include STSTEM_WARNING_POP
    }

    return result;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetTranslation(Real t0) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Polynomial factor{ ContainerType{ -t0, Math::GetValue(1) } };
    const auto degree = GetDegree();
    Polynomial result{ ContainerType{ coeff.at(degree) } };
    for (auto index = degree - 1; 0 <= index; --index)
    {
        result = coeff.at(index) + factor * result;
    }

    return result;
}

template <typename Real>
void Mathematics::Polynomial<Real>::EliminateLeadingZeros(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = GetCompressDegree(epsilon);

    const auto size = degree + 1;
    coeff.resize(size);
}

template <typename Real>
void Mathematics::Polynomial<Real>::Compress(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = GetCompressDegree(epsilon);

    if (0 <= degree)
    {
        Polynomial result{ degree };

        result[degree] = Math::GetValue(1);
        for (auto i = 0; i < degree; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            result[i] = coeff[i] / coeff[degree];

#include STSTEM_WARNING_POP
        }

        SetValue(std::move(result.coeff));
    }
}

template <typename Real>
int Mathematics::Polynomial<Real>::GetCompressDegree(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto degree = GetDegree();

    for (auto i = degree; 0 <= i; --i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (Math::FAbs(coeff[i]) <= epsilon)
        {
            --degree;
        }
        else
        {
            break;
        }

#include STSTEM_WARNING_POP
    }

    return degree;
}

template <typename Real>
typename Mathematics::Polynomial<Real>::PolynomialDivide Mathematics::Polynomial<Real>::Divide(const Polynomial& divisor, Real epsilon) const
{
    const auto degree = GetDegree();
    const auto divisorDegree = divisor.GetDegree();

    const auto quotientDegree = degree - divisorDegree;
    if (0 <= quotientDegree)
    {
        Polynomial quotient{ quotientDegree };

        // 临时存储的余数。
        Polynomial remainder{ *this };

        // 做除法（欧几里得算法）。
        auto inv = Math::GetValue(1) / divisor[divisorDegree];
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
Mathematics::Polynomial<Real> Mathematics::GreatestCommonDivisor(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon)
{
    auto a = rhs.GetDegree() <= lhs.GetDegree() ? lhs : rhs;
    auto b = rhs.GetDegree() <= lhs.GetDegree() ? rhs : lhs;

    const Polynomial<Real> zero{ typename Polynomial<Real>::ContainerType{ Math<Real>::GetValue(0) } };
    if (Approximate(a, zero, epsilon) || Approximate(b, zero, epsilon))
    {
        return (!Approximate(a, zero) ? a : zero);
    }

    a.Compress(epsilon);
    b.Compress(epsilon);

    for (;;)
    {
        const auto polynomialDivide = Divide(a, b);
        if (!Approximate(polynomialDivide.GetRemainder(), zero, epsilon))
        {
            a = b;
            b = polynomialDivide.GetRemainder();
            b.Compress(epsilon);
        }
        else
        {
            b.Compress(epsilon);
            break;
        }
    }

    return b;
}

template <typename Real>
std::vector<Mathematics::Polynomial<Real>> Mathematics::SquareFreeFactorization(const Polynomial<Real>& f)
{
    std::vector<Polynomial<Real>> factors{};

    auto fder = f.GetDerivative();

    auto a = GreatestCommonDivisor(f, fder);
    auto polynomialDivide = Divide(f, a);
    auto b = polynomialDivide.GetQuotient();
    auto r = polynomialDivide.GetRemainder();

    polynomialDivide = Divide(fder, a);
    auto c = polynomialDivide.GetQuotient();
    r = polynomialDivide.GetRemainder();
    auto d = c - b.GetDerivative();

    do
    {
        a = GreatestCommonDivisor(b, d);
        factors.emplace_back(a);
        polynomialDivide = Divide(b, a);
        auto q = polynomialDivide.GetQuotient();
        r = polynomialDivide.GetRemainder();
        b = std::move(q);

        polynomialDivide = Divide(d, a);
        c = polynomialDivide.GetQuotient();
        r = polynomialDivide.GetRemainder();

        d = c - b.GetDerivative();
    } while (0 < b.GetDegree());

    return factors;
}

template <typename T>
bool Mathematics::Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, const T epsilon)
{
    if (lhs.GetDegree() != rhs.GetDegree())
    {
        return false;
    }
    else
    {
        for (auto i = 0; i <= rhs.GetDegree(); ++i)
        {
            if (!Math<T>::Approximate(lhs[i], rhs[i], epsilon))
            {
                return false;
            }
        }

        return true;
    }
}

template <typename Real>
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
