// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 09:48)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <vector>

namespace Mathematics
{
	// N是你想要元整数的32位字节的数目。
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

		// 算术更新。
		IntegerDataOperator& operator+= (const IntegerData& rhs);
		IntegerDataOperator& operator-= (const IntegerData& rhs);
		IntegerDataOperator& operator*= (const IntegerData& rhs);

		// 如果要同时求出商和余数，
		// 直接调用IntegerDataAnalysis::GetDivisionModulo		
		IntegerDataOperator& operator/= (const IntegerData& rhs);
		IntegerDataOperator& operator%= (const IntegerData& rhs);

		// 移位更新。
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
