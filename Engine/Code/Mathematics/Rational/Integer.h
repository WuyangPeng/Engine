// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 10:53)

#ifndef MATHEMATICS_RATIONAL_INTEGER_H
#define MATHEMATICS_RATIONAL_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "IntegerData.h"
#include "IntegerDivisionModulo.h"

#include <boost/operators.hpp>
#include <vector>
#include <iosfwd>

// IntegerData只定义初始化和[]运算符。
// IntegerDataAmend定义修改IntegerData的函数。
// IntegerDataAnalysis定义解析函数。
// IntegerDataOperator定义数学运算符。
// IntegerMultiplication定义乘法。
// IntegerDivisionModulo定义除法和求余。
// Integer只包含必要的外部接口。
namespace Mathematics
{
	// N是你想要元整数的32位字节的数目。
	template <int N>
	class Integer : private boost::integer_arithmetic<Integer<N>,
						    boost::totally_ordered<Integer<N>,
						    boost::shiftable<Integer<N>>>> 
	{
	public:		
		using ClassType = Integer<N>;
		using IntegerDivisionModulo = IntegerDivisionModulo<N>;

	public:		
		Integer();
		explicit Integer(const std::vector<uint16_t>& data);
		Integer(int count,const uint16_t* data);

		template<typename T>
		explicit Integer(T value);	
	
		template <int Other>
		Integer(const Integer<Other>& rhs);

		CLASS_INVARIANT_DECLARE;

		bool IsZero() const;
		void SetZero();
		NumericalValueSymbol GetSign () const;	

		uint16_t& operator[](int index);
		const uint16_t& operator[](int index) const;

		// 算术运算。
		const Integer operator- () const;
		const Integer GetAbsoluteValue() const;

		// 算术更新。
		Integer& operator+= (const Integer& rhs);
		Integer& operator-= (const Integer& rhs);
		Integer& operator*= (const Integer& rhs);

		// 如果要同时求出商和余数，
		// 直接调用GetDivisionModulo
		const IntegerDivisionModulo GetDivisionModulo(const Integer& rhs) const;
		Integer& operator/= (const Integer& rhs);	
		Integer& operator%= (const Integer& rhs);	

		// 移位更新。
		Integer& operator<<= (int shift);
		Integer& operator>>= (int shift);

		int GetLeadingBlock() const;
		int GetTrailingBlock() const;
		int GetLeadingBit(int index) const;  
		int GetTrailingBit(int index) const; 
		int GetLeadingBit() const;
		int GetTrailingBit() const;	

		void SetBit (int index, bool on);
		bool GetBit (int index) const;	

		// 比较	
		bool operator== (const Integer& rhs) const;
		bool operator< (const Integer& rhs) const;		

		// 返回值若被截断，抛出异常
		template <typename T>
		T GetValue() const;	

		void Print(std::ostream& os) const;

	private:
		typedef IntegerData<N> IntegerData;

	private:
		IntegerData m_IntegerData;
	};	

	template <int N>
	std::ostream& operator<< (std::ostream& os,const Integer<N>& integer);
}

#endif // MATHEMATICS_RATIONAL_INTEGER_H
