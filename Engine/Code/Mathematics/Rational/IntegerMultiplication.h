///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 15:53)

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

        NODISCARD IntegerData GetMultiplication() const noexcept;

    private:
        void Calculate();
        void Product();
        void CalculateProduct(uint32_t lhsBit, uint32_t lhsIndex);
        NODISCARD uint32_t CalculateResult(uint32_t lhsIndex);
        void DetermineCarry(uint32_t carry, uint32_t resultBufferIndex);
        void OverflowTest();
        void Negative();

    private:
        using DataType = std::vector<uint16_t>;

        static constexpr auto intSize = 2 * N;
        static constexpr auto intLast = intSize - 1;
        static constexpr uint16_t symbol{ 0x8000 };
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr auto integerCarry = 0x00010000u;

        const IntegerData& lhsData;
        const IntegerData& rhsData;
        NumericalValueSymbol productSign;
        IntegerData absLhsData;
        IntegerData absRhsData;
        DataType product;
        DataType result;
        IntegerData multiplication;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_H
