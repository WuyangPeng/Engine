// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 11:00)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "IntegerTraits.h"

#include <boost/type_traits/is_arithmetic.hpp>

namespace Mathematics
{
	template <int N>
	class IntegerData;

	template <int N,typename T>
	class IntegerDataConversion
	{
	public:	
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = IntegerDataConversion<N,T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;
		typedef IntegerData<N> IntegerData;		

	public:		
		// ����ֵ�����ضϣ��׳��쳣
		explicit IntegerDataConversion(const IntegerData& data);

		CLASS_INVARIANT_DECLARE;
		
		T GetValue() const;	

	private:
		void Init(const SignedIntegerType&);
		void Init(const UnsignedIntegerType&);
		void Init(const FloatType&);
		void Init(const DoubleType&);
		void InitToFloatingPoint();
		void CalculateMantissa();
		void CalculateConversionValue();
		void Negative();	
		void SignedIntegerNegative();
		
	private:
		IntegerData m_AbsData;
		int m_Shifting;
		uint64_t m_Mantissa;
		NumericalValueSymbol m_Symbol;
		T m_Value;
	};		
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
