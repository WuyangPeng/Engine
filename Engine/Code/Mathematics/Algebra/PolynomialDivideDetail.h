// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 14:15)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H

#include "Polynomial.h"
#include "AlgebraTraits.h"
#include "PolynomialDivide.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::PolynomialDivide <Real>
	::PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder)
	: m_Quotient{ quotient }, m_Remainder{ remainder }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialDivide <Real>
	::IsValid() const noexcept
{
	return true;
}
#endif	// OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>
	::GetQuotient() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Quotient;
}

template <typename Real>
typename const Mathematics::PolynomialDivide<Real>::Polynomial Mathematics::PolynomialDivide<Real>
	::GetRemainder() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Remainder;
}

#endif // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_DETAIL_H
