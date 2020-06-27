// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 09:49)
#ifndef MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
#define MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "IntegerTraits.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
	template <int N, typename T>
	class RationalConversion
	{
	public:
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = RationalConversion<N, T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;
		using Rational = SignRational<N>;
		using Integer = Integer<N>;

	public:
		// ����ֵ�����ضϣ��׳��쳣
		explicit RationalConversion(const Rational& rational);

		CLASS_INVARIANT_DECLARE;

		T GetValue() const;

	private:
		void Init(const SignedIntegerType&);
		void Init(const UnsignedIntegerType&);
		void Init(const FloatType&);
		void Init(const DoubleType&);
		void InitToFloatingPoint();
		void InitToIntegral();

		void CorrectWithShifting();
		void CalculateMantissa();
		void Negative();

	private:
		Integer m_AbsNumerator;
		Integer m_AbsDenominator;
		// �õ����Ӻͷ�ĸ����ʼλ�Ĳ
		int m_Shifting;
		NumericalValueSymbol m_Symbol;
		uint64_t m_Mantissa;
		T m_Value;
	};
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
