// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 11:05)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H

#include "Mathematics/MathematicsDll.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
	template <int N>
	class IntegerData;

	template <int N>
	class IntegerDataAnalysis;

	// 支持除法和取模。
	template <int N>
	class IntegerDivisionMultiple : private boost::noncopyable
	{
	public:
		using ClassType = IntegerDivisionMultiple<N>;
		using IntegerData = IntegerData<N>;
		using IntegerDataAnalysis = IntegerDataAnalysis<N>;

	public:
		IntegerDivisionMultiple(const IntegerData& absNumerator, const IntegerData& absDenominator);

		CLASS_INVARIANT_DECLARE;		

		const IntegerData GetQuotient() const;
		const IntegerData GetRemainder() const;

	private: 
		void Calculate();		
		void Adjust();
		void Recover();
		void Calculate(int quotientInit);

	private:
		static constexpr uint32_t sm_Low{ 0x0000FFFF };
		static constexpr uint32_t sm_High{ 0xFFFF0000 };
		static constexpr uint32_t sm_Carry{ 0x00010000 };

		const IntegerData& m_AbsNumerator;
		const IntegerData& m_AbsDenominator;	
		IntegerData m_AdjustNumerator;
		IntegerData m_AdjustDenominator;
		int m_NumeratorInit;
		int m_DenominatorInit;
		int m_Adjust;
		uint32_t m_FirstDigit;
		uint32_t m_SecondDigit;
		uint32_t m_RemainderHat;
		IntegerData m_Quotient;
		IntegerData m_Remainder; 		
	};	
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
