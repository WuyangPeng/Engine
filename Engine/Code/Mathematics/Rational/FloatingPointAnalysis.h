/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "Flags/FloatingPointAnalysisType.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FloatingPointAnalysis final
    {
    public:
        static_assert(std::is_floating_point_v<T>, "T must be floating point.");

        using ClassType = FloatingPointAnalysis<T>;

        using TraitsType = typename IntegerTraits<T>::TraitsType;
        using IntegerType = typename TraitsType::IntegerType;

        static_assert(sizeof(IntegerType) == sizeof(T));

    public:
        explicit FloatingPointAnalysis(T value) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 内存表示：
        // 符号位（1）、指数位（float8位、double11位）、尾数位（float23位、double52位），获取未经处理的存储值。
        NODISCARD IntegerType GetSymbolValue() const noexcept;
        NODISCARD IntegerType GetExponent() const noexcept;
        NODISCARD IntegerType GetMantissa() const noexcept;

        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD FloatingPointAnalysisType GetType() const noexcept;
        NODISCARD int GetRealExponent() const;
        NODISCARD IntegerType GetRealMantissa() const noexcept;

    private:
        static constexpr auto symbol = TraitsType::symbol;
        static constexpr auto symbolShifting = TraitsType::symbolShifting;
        static constexpr auto exponent = TraitsType::exponent;
        static constexpr auto exponentShifting = TraitsType::exponentShifting;
        static constexpr auto maxExponent = exponent >> exponentShifting;
        static constexpr auto realExponentDifference = TraitsType::realExponentDifference;
        static constexpr auto mantissa = TraitsType::mantissa;
        static constexpr auto quietNaN = TraitsType::quietNaN;

    private:
        T value;
    };
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
