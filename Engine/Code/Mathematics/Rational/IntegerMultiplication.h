// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:49)

#ifndef MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H
#define MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
	template <int N>
	class IntegerMultiplication : private boost::noncopyable
	{
	public:
		using ClassType = IntegerMultiplication<N>;
		using IntegerData = IntegerData<N>;
		using IntegerDataAnalysis = IntegerDataAnalysis<N>;

	public:
		IntegerMultiplication(const IntegerData& lhs, const IntegerData& rhs);

		CLASS_INVARIANT_DECLARE;

		const IntegerData GetMultiplication() const noexcept;

	private:
		void Calculate();
		void Product();
		void CalculateProduct(uint32_t lhsBit, uint32_t lhsIndex);
		uint32_t CalculateResult(uint32_t lhsIndex);
		void DetermineCarry(uint32_t carry, uint32_t resultBufferIndex);
		void OverflowTest();
		void Negative();

	private:
		static constexpr uint32_t sm_IntSize{ 2 * N };
		static constexpr int32_t sm_IntLast{ sm_IntSize - 1 };
		static constexpr uint16_t sm_Symbol{ 0x8000 };
		static constexpr uint32_t sm_Low{ 0x0000FFFF };
		static constexpr uint32_t sm_High{ 0xFFFF0000 };
		static constexpr uint32_t sm_Carry{ 0x00010000 };

		const IntegerData& m_LhsData;
		const IntegerData& m_RhsData;
		NumericalValueSymbol m_ProductSign;
		IntegerData m_AbsLhsData;
		IntegerData m_AbsRhsData;
		std::vector<uint16_t> m_Product;
		std::vector<uint16_t> m_Result;
		IntegerData m_Multiplication;
	};
}

#endif // MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H
