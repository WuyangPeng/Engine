// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 10:53)

#ifndef MATHEMATICS_RATIONAL_INTEGER_H
#define MATHEMATICS_RATIONAL_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "IntegerData.h"
#include "IntegerDivisionModulo.h"

#include <boost/operators.hpp>
#include <vector>
#include <iosfwd>

// IntegerDataֻ�����ʼ����[]�������
// IntegerDataAmend�����޸�IntegerData�ĺ�����
// IntegerDataAnalysis�������������
// IntegerDataOperator������ѧ�������
// IntegerMultiplication����˷���
// IntegerDivisionModulo������������ࡣ
// Integerֻ������Ҫ���ⲿ�ӿڡ�
namespace Mathematics
{
	// N������ҪԪ������32λ�ֽڵ���Ŀ��
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

		// �������㡣
		const Integer operator- () const;
		const Integer GetAbsoluteValue() const;

		// �������¡�
		Integer& operator+= (const Integer& rhs);
		Integer& operator-= (const Integer& rhs);
		Integer& operator*= (const Integer& rhs);

		// ���Ҫͬʱ����̺�������
		// ֱ�ӵ���GetDivisionModulo
		const IntegerDivisionModulo GetDivisionModulo(const Integer& rhs) const;
		Integer& operator/= (const Integer& rhs);	
		Integer& operator%= (const Integer& rhs);	

		// ��λ���¡�
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

		// �Ƚ�	
		bool operator== (const Integer& rhs) const;
		bool operator< (const Integer& rhs) const;		

		// ����ֵ�����ضϣ��׳��쳣
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
