///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:06)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <vector>

namespace Mathematics
{
    // N是你想要元整数的32位字节的数目。
    template <int N>
    class IntegerDataOperator final
    {
    public:
        using ClassType = IntegerDataOperator<N>;
        using IntegerDataAmend = IntegerDataAmend<N>;
        using IntegerData = IntegerData<N>;
        using IntegerDataAnalysis = IntegerDataAnalysis<N>;

    public:
        explicit IntegerDataOperator(IntegerData& master) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 算术更新。
        IntegerDataOperator& operator+=(const IntegerData& rhs);
        IntegerDataOperator& operator-=(const IntegerData& rhs);
        IntegerDataOperator& operator*=(const IntegerData& rhs);

        // 如果要同时求出商和余数，
        // 直接调用IntegerDataAnalysis::GetDivisionModulo
        IntegerDataOperator& operator/=(const IntegerData& rhs);
        IntegerDataOperator& operator%=(const IntegerData& rhs);

        // 移位更新。
        IntegerDataOperator& operator<<=(int shift);
        IntegerDataOperator& operator>>=(int shift);

    private:
        static constexpr auto intSize = 2 * N;
        static constexpr auto intLast = intSize - 1;
        static constexpr auto carry = 0x00010000u;
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr uint16_t symbol{ 0x8000 };
        static constexpr auto positive = 0xFFFFFFFFu;

        IntegerData& master;
        IntegerDataAmend amend;
        IntegerDataAnalysis analysis;
    };

    template <int N>
    NODISCARD IntegerData<N> operator+(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    NODISCARD IntegerData<N> operator-(const IntegerData<N>& lhs, const IntegerData<N>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
