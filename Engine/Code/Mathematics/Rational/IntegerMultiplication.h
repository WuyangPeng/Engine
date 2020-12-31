///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:24)

#ifndef MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H
#define MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    template <int N>
    class IntegerMultiplication final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerMultiplication<N>;
        using IntegerData = IntegerData<N>;
        using IntegerDataAnalysis = IntegerDataAnalysis<N>;

    public:
        IntegerMultiplication(const IntegerData& lhs, const IntegerData& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const IntegerData GetMultiplication() const noexcept;

    private:
        void Calculate();
        void Product();
        void CalculateProduct(uint32_t lhsBit, uint32_t lhsIndex);
        [[nodiscard]] uint32_t CalculateResult(uint32_t lhsIndex);
        void DetermineCarry(uint32_t carry, uint32_t resultBufferIndex);
        void OverflowTest();
        void Negative();

    private:
        using DataType = std::vector<uint16_t>;

        static constexpr auto sm_IntSize = 2 * N;
        static constexpr auto sm_IntLast = sm_IntSize - 1;
        static constexpr uint16_t sm_Symbol{ 0x8000 };
        static constexpr auto sm_Low = 0x0000FFFFu;
        static constexpr auto sm_High = 0xFFFF0000u;
        static constexpr auto sm_Carry = 0x00010000u;

        const IntegerData& m_LhsData;
        const IntegerData& m_RhsData;
        NumericalValueSymbol m_ProductSign;
        IntegerData m_AbsLhsData;
        IntegerData m_AbsRhsData;
        DataType m_Product;
        DataType m_Result;
        IntegerData m_Multiplication;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H
