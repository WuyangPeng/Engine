// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 09:48)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

namespace Mathematics
{
	// 支持除法和取模。
	template <int N>
	class IntegerDivisionModulo
	{
	public:
		using ClassType = IntegerDivisionModulo<N>;
		using IntegerData = IntegerData<N>;
		using IntegerDataAnalysis = IntegerDataAnalysis<N>;

	public:
		IntegerDivisionModulo(const IntegerData& division, const IntegerData& modulo);

	#ifdef OPEN_CLASS_INVARIANT
		CLASS_INVARIANT_DECLARE;
		bool IsCorrect() const;
	#endif // OPEN_CLASS_INVARIANT

		const IntegerData GetQuotient() const;
		const IntegerData GetRemainder() const;

	private:
		void Calculate();
		void DivisionSingle();
		void DivisionMultiple();
		void CalculateRemainder();

	private:
		static constexpr uint32_t sm_Low{ 0x0000FFFF };
		static constexpr uint32_t sm_High{ 0xFFFF0000 };
		static constexpr uint32_t sm_Carry{ 0x00010000 };

		IntegerData m_Numerator;
		IntegerData m_Denominator;
		IntegerData m_AbsNumerator;
		IntegerData m_AbsDenominator;
		IntegerData m_Quotient;
		IntegerData m_Remainder;
	};
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
