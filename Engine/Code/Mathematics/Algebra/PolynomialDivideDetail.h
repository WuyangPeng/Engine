/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 10:58)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H

#include "Polynomial.h"
#include "PolynomialDivide.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::PolynomialDivide<Real>::PolynomialDivide(Polynomial quotient, Polynomial remainder) noexcept
    : quotient{ std::move(quotient) }, remainder{ std::move(remainder) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::PolynomialDivide<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetQuotient() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return quotient;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>::GetRemainder() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return remainder;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
