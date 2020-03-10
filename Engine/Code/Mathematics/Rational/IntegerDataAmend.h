// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 10:59)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
	// N������ҪԪ������32λ�ֽڵ���Ŀ��
	template <int N>
	class IntegerData;

	template <int N>
	class IntegerDataAmend : boost::noncopyable
	{
	public:		
		using ClassType = IntegerDataAmend<N>;
		using IntegerData = IntegerData<N>;

	public:
		explicit IntegerDataAmend(IntegerData& master);
	 
		CLASS_INVARIANT_DECLARE;

		void Negative();		
		void FromUnsignedInt(int index, uint32_t value);	
		void SetValue(int beginIndex,int endIndex,uint32_t value);

	private:	
		static constexpr uint32_t sm_IntSize{ 2 * N };
		static constexpr uint32_t sm_Carry{ 0x00010000 };
		static constexpr uint32_t sm_Low{ 0x0000FFFF };

		IntegerData& m_Master;
	};	
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
