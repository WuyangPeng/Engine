// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 09:47)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "IntegerTraits.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
	template <int N,typename T>
	class IntegerDataConversion
	{
	public:	
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = IntegerDataConversion<N,T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;
		typedef IntegerData<N> IntegerData;		

	public:		
		// 返回值若被截断，抛出异常
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
