// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:44)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
#define MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"
#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
	template <typename T>
	class ConversionRational
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = ConversionRational<T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;

	public:
		explicit ConversionRational(T value);

		CLASS_INVARIANT_DECLARE;

		uint64_t GetNumeratorMantissa() const;
		uint64_t GetDenominatorMantissa() const;
		NumericalValueSymbol GetSymbol() const;
		int GetNumeratorShifting() const;
		int GetDenominatorShifting() const;
		int GetMaxShifting() const;
		int GetReducibilityShifting() const;

		template <int N>
		bool IsCanConversion() const;

		template <int N>
		const Integer<N> GetNumerator() const;

		template <int N>
		const Integer<N> GetDenominator() const;

	private:
		void Init(T value, const SignedIntegerType&);
		void Init(T value, const UnsignedIntegerType&);
		void Init(T value, const FloatType&);
		void Init(T value, const DoubleType&);
		void InitFloatingPoint(T value);
		int GetAssignmentNumeratorShifting(int bit) const;
		int GetAssignmentDenominatorShifting(int bit) const;
		uint64_t GetAssignmentNumeratorMantissa(int bit) const;
		uint64_t GetAssignmentDenominatorMantissa(int bit) const;

	private:
		int m_NumeratorShifting;
		int m_DenominatorShifting;
		uint64_t m_NumeratorMantissa;
		uint64_t m_DenominatorMantissa;
		NumericalValueSymbol m_Symbol;
		int m_MaxShifting;
		int m_ReducibilityShifting;
	};
}

#endif // MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
