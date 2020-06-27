// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:14)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class PolynomialDivide
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = PolynomialDivide<Real>;
		using Polynomial = Polynomial<Real>;

	public:
		PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder);

		CLASS_INVARIANT_DECLARE;

		const Polynomial GetQuotient() const;
		const Polynomial GetRemainder() const;

	private:
		Polynomial m_Quotient;
		Polynomial m_Remainder;
	};

	using PolynomialDividef = PolynomialDivide<float>;
	using PolynomialDivided = PolynomialDivide<double>;
}

#endif // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
