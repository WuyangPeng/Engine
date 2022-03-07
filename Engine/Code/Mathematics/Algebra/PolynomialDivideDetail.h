///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 15:46)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialDivide<Real>::PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder)
    : quotient{ quotient }, remainder{ remainder }
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
typename Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetQuotient() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quotient;
}

template <typename Real>
typename Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetRemainder() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return remainder;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
