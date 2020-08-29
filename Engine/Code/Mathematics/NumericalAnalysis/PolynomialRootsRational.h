// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/QuantityType.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/SignRational.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class PolynomialRootsRational
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = PolynomialRootsRational<Real>;
		using PolynomialRational = SignRational<16 * sizeof(Real)>;
		using Math = Math<Real>;

	public:
		explicit PolynomialRootsRational(Real epsilon = Math::sm_Epsilon);
		~PolynomialRootsRational();
		PolynomialRootsRational(const PolynomialRootsRational& rhs);
		PolynomialRootsRational& operator=(const PolynomialRootsRational& rhs);

		CLASS_INVARIANT_DECLARE;

		int GetQuantity() const;
		Real GetRoot(int index) const;
		int GetMultiplicity(int index) const;

		// p(x) = constant + once * x
		bool Linear(Real constant, Real once);
		bool Linear(const PolynomialRational& constant, const PolynomialRational& once);

		// p(x) = constant + once * x + secondary * x^2
		// m(x) = constant + once * x + x^2
		bool Quadratic(Real constant, Real once, Real secondary);
		bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);
		bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once);

		// p(x) = constant + once * x + secondary * x^2 + thrice * x^3
		// m(x) = constant + once * x + secondary * x^2 + x^3
		bool Cubic(Real constant, Real once, Real secondary, Real thrice);
		bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice);
		bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);

		// p(x) = constant + once * x + secondary * x^2 + thrice * x^3 + quartic * x^4 (首一当 c4 = 1)
		// m(x) = constant + once * x + secondary * x^2 + thrice * x^3 + x^4
		bool Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
		bool Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary,
					 const PolynomialRational& thrice, const PolynomialRational& quartic);
		bool Quartic(const PolynomialRational& constant, const PolynomialRational& once,
					 const PolynomialRational& secondary, const PolynomialRational& thrice);

	private:
		void SortRoots();

	private:
		static const PolynomialRational sm_Zero;
		static const PolynomialRational sm_One;
		static constexpr auto sm_MaxRoot = 4;

		int m_Quantity;
		Real m_Root[sm_MaxRoot];
		int m_Multiplicity[sm_MaxRoot];
		Real m_Epsilon;
	};

	using PolynomialRootsRationalf = PolynomialRootsRational<float>;
	using PolynomialRootsRationald = PolynomialRootsRational<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H
