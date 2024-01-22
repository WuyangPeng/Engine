/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:28)

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

        // �ڴ��ʾ��
        // ����λ��1����ָ��λ��float8λ��double11λ����β��λ��float23λ��double52λ������ȡδ������Ĵ洢ֵ��
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
