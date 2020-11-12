///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 13:27)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_ACHIEVE_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialDivide<Real>::PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder)
    : m_Quotient{ quotient }, m_Remainder{ remainder }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialDivide<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetQuotient() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Quotient;
}

template <typename Real>
typename const Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetRemainder() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Remainder;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_ACHIEVE_H
