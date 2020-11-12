///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 11:30)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "Detail/PolynomialImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(int degree)
    : m_Impl{ std::make_shared<ImplType>(degree) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const ContainerType& coeff)
    : m_Impl{ std::make_shared<ImplType>(coeff) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(const Polynomial& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator=(const Polynomial& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    Polynomial temp{ rhs };

    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_POP

template <typename Real>
void Mathematics::Polynomial<Real>::Swap(Polynomial& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::Polynomial<Real>::Polynomial(Polynomial&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator=(Polynomial&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polynomial<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Polynomial<Real>::ResetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(0 <= degree, "构造的多项式degree为负数！");

    Polynomial<Real> rhs{ degree };

    Swap(rhs);
}

template <typename Real>
int Mathematics::Polynomial<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDegree();
}

template <typename Real>
const Real& Mathematics::Polynomial<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)[index];
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

    return m_Impl->GetBegin();
}

template <typename Real>
Real Mathematics::Polynomial<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEnd();
}

template <typename Real>
Real Mathematics::Polynomial<Real>::operator()(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)(value);
}

template <typename Real>
typename Mathematics::Polynomial<Real>::ContainerType Mathematics::Polynomial<Real>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetValue();
}

template <typename Real>
void Mathematics::Polynomial<Real>::SetValue(const ContainerType& coeff)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->SetValue(coeff);
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Polynomial<Real> result{ *this };

    result.m_Impl->Negative();

    return result;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (GetDegree() <= rhs.GetDegree())
    {
        Polynomial temp{ rhs };
        Swap(temp);
        m_Impl->Plus(*temp.m_Impl);
    }
    else
    {
        m_Impl->Plus(*rhs.m_Impl);
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(const Polynomial& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (GetDegree() <= rhs.GetDegree())
    {
        Polynomial temp{ rhs };
        Swap(temp);
        m_Impl->Minus(*temp.m_Impl);
    }
    else
    {
        m_Impl->Plus(*rhs.m_Impl);
    }

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
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator+=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*m_Impl)[0] += scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator-=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    (*m_Impl)[0] -= scalar;

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& coeff : *m_Impl)
    {
        coeff *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::Polynomial<Real>& Mathematics::Polynomial<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        for (auto& coeff : *m_Impl)
        {
            coeff /= scalar;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"s));
    }

    return *this;
}

template <typename Real>
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetDerivative() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    if (0 < degree)
    {
        Polynomial result{ degree - 1 };

        for (auto index = 0; index < degree; ++index)
        {
            const auto nextIndex = index + 1;
            result[index] = nextIndex * (*m_Impl)[nextIndex];
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
const Mathematics::Polynomial<Real> Mathematics::Polynomial<Real>::GetInversion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

    Polynomial result{ degree };
    for (auto i = 0; i <= degree; ++i)
    {
        result[i] = (*m_Impl)[degree - i];
    }

    return result;
}

template <typename Real>
void Mathematics::Polynomial<Real>::Compress(Real epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = m_Impl->GetCompressDegree(epsilon);

    if (0 <= degree)
    {
        Polynomial result{ degree };

        result[degree] = Math::GetValue(1);
        for (auto i = 0; i < degree; ++i)
        {
            result[i] = (*m_Impl)[i] / (*m_Impl)[degree];
        }

        Swap(result);
    }
}

template <typename Real>
typename const Mathematics::Polynomial<Real>::PolynomialDivide Mathematics::Polynomial<Real>::Divide(const Polynomial& divisor, Real epsilon) const
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
        auto remainderDegree = divisorDegree - 1;
        while (0 < remainderDegree && Math::FAbs(remainder[remainderDegree]) < epsilon)
        {
            --remainderDegree;
        }

        if (remainderDegree == 0 && Math::FAbs(remainder[0]) < epsilon)
        {
            remainder[0] = Math::GetValue(0);
        }

        Polynomial correctRemainder{ remainderDegree };

        for (auto i = 0; i < remainderDegree; ++i)
        {
            correctRemainder[i] = remainder[i];
        }

        return PolynomialDivide{ quotient, correctRemainder };
    }
    else
    {
        Polynomial quotient{ 0 };
        Polynomial remainder{ *this };

        return PolynomialDivide{ quotient, *this };
    }
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_ACHIEVE_H
