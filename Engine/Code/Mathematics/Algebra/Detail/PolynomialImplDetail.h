///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 9:56)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_DETAIL_H

#include "PolynomialImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::PolynomialImpl<Real>::PolynomialImpl(int degree)
    : m_Coeff{}
{
    if (degree < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"s));
    }

    const auto size = degree + 1;
    m_Coeff.resize(size);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::PolynomialImpl<Real>::PolynomialImpl(const ContainerType& coeff)
    : m_Coeff{}
{
    if (coeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }
    else
    {
        m_Coeff = coeff;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialImpl<Real>::IsValid() const noexcept
{
    if (!m_Coeff.empty())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::PolynomialImpl<Real>::ResetDegree(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (degree < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("构造的多项式degree为负数！"));
    }

    m_Coeff.clear();
    m_Coeff.resize(degree + 1);
    m_Coeff.shrink_to_fit();
}

template <typename Real>
int Mathematics::PolynomialImpl<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Coeff.size() - 1);
}

template <typename Real>
typename Mathematics::PolynomialImpl<Real>::ContainerType Mathematics::PolynomialImpl<Real>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff;
}

template <typename Real>
void Mathematics::PolynomialImpl<Real>::SetValue(const ContainerType& coeff)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (coeff.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式为空。"s));
    }
    else
    {
        m_Coeff = coeff;
    }
}

template <typename Real>
typename Mathematics::PolynomialImpl<Real>::ContainerTypeConstIter Mathematics::PolynomialImpl<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff.cbegin();
}

template <typename Real>
typename Mathematics::PolynomialImpl<Real>::ContainerTypeConstIter Mathematics::PolynomialImpl<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff.cend();
}

template <typename Real>
typename Mathematics::PolynomialImpl<Real>::ContainerTypeIter Mathematics::PolynomialImpl<Real>::begin() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff.begin();
}

template <typename Real>
typename Mathematics::PolynomialImpl<Real>::ContainerTypeIter Mathematics::PolynomialImpl<Real>::end() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff.end();
}

template <typename Real>
const Real& Mathematics::PolynomialImpl<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coeff.at(index);
}

template <typename Real>
Real& Mathematics::PolynomialImpl<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Real Mathematics::PolynomialImpl<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Coeff[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::PolynomialImpl<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Coeff[m_Coeff.size() - 1];
#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::PolynomialImpl<Real>::operator()(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto degree = GetDegree();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto result = m_Coeff[degree];
    for (auto i = degree - 1; 0 <= i; --i)
    {
        result *= value;
        result += m_Coeff[i];
    }

#include STSTEM_WARNING_POP

    return result;
}

template <typename Real>
void Mathematics::PolynomialImpl<Real>::Negative() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto& value : m_Coeff)
    {
        value = -value;
    }
}

template <typename Real>
void Mathematics::PolynomialImpl<Real>::Plus(const PolynomialImpl& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Coeff.size() < rhs.m_Coeff.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不允许要增加的多项式大小比原多项式大。"s));
    }

    for (auto i = 0u; i < m_Coeff.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Coeff[i] += rhs.m_Coeff[i];
#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::PolynomialImpl<Real>::Minus(const PolynomialImpl& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Coeff.size() < rhs.m_Coeff.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不允许要增加的多项式大小比原多项式大。"s));
    }

    for (auto i = 0u; i < m_Coeff.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Coeff[i] -= rhs.m_Coeff[i];
#include STSTEM_WARNING_POP
    }
}

template <typename Real>
int Mathematics::PolynomialImpl<Real>::GetCompressDegree(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto degree = GetDegree();

    for (auto i = degree; 0 <= i; --i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (Math::FAbs(m_Coeff[i]) <= epsilon)
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

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_DETAIL_H
