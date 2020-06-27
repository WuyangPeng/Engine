// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 09:48)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <vector>

namespace Mathematics
{
	// N������ҪԪ������32λ�ֽڵ���Ŀ��
	template <int N>
	class IntegerDataOperator
	{
	public:
		using ClassType = IntegerDataOperator<N>;
		using IntegerDataAmend = IntegerDataAmend<N>;
		using IntegerData = IntegerData<N>;
		using IntegerDataAnalysis = IntegerDataAnalysis<N>;

	public:
		explicit IntegerDataOperator(IntegerData& master);

		CLASS_INVARIANT_DECLARE;

		// �������¡�
		IntegerDataOperator& operator+= (const IntegerData& rhs);
		IntegerDataOperator& operator-= (const IntegerData& rhs);
		IntegerDataOperator& operator*= (const IntegerData& rhs);

		// ���Ҫͬʱ����̺�������
		// ֱ�ӵ���IntegerDataAnalysis::GetDivisionModulo		
		IntegerDataOperator& operator/= (const IntegerData& rhs);
		IntegerDataOperator& operator%= (const IntegerData& rhs);

		// ��λ���¡�
		IntegerDataOperator& operator<<= (int shift);
		IntegerDataOperator& operator>>= (int shift);

	private:
		static constexpr uint32_t sm_IntSize{ 2 * N };
		static constexpr uint32_t sm_IntLast{ sm_IntSize - 1 };
		static constexpr uint32_t sm_Carry{ 0x00010000 };
		static constexpr uint32_t sm_Low{ 0x0000FFFF };
		static constexpr uint32_t sm_High{ 0xFFFF0000 };
		static constexpr uint16_t sm_Symbol{ 0x8000 };
		static constexpr uint32_t sm_Positive{ 0xFFFFFFFF };

		IntegerData& m_Master;
		IntegerDataAmend m_Amend;
		IntegerDataAnalysis m_Analysis;
	};

	template <int N>
	IntegerData<N> operator+ (const IntegerData<N>& lhs, const IntegerData<N>& rhs);

	template <int N>
	IntegerData<N> operator- (const IntegerData<N>& lhs, const IntegerData<N>& rhs);
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
