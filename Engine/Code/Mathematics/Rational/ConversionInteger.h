// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:44)

#ifndef MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
	template<typename T>
	class ConversionInteger
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = ConversionInteger<T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;

	public:
		explicit ConversionInteger(T value);

		CLASS_INVARIANT_DECLARE;

		int GetShifting() const;
		uint64_t GetMantissa() const;
		NumericalValueSymbol GetSymbol() const;
		int GetMaxMantissaBit() const;
		uint64_t GetShiftingMantissa() const;
		int GetBeginBlock() const;

		int GetMantissaSize() const;
		int GetCopySize() const;

	private:
		void Init(T value, const SignedIntegerType&);
		void Init(T value, const UnsignedIntegerType&);
		void Init(T value, const FloatType&);
		void Init(T value, const DoubleType&);
		void Amendment();
		void ShiftingMantissa();

	private:
		int m_Shifting;
		uint64_t m_Mantissa;
		NumericalValueSymbol m_Symbol;
		int m_MaxMantissaBit;
		uint64_t m_ShiftingMantissa;
	};
}

#endif // MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H
