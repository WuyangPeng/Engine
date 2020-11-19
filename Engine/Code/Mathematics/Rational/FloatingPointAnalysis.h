///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/18 17:07)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "Flags/FloatingPointAnalysisType.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

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
        [[nodiscard]] IntegerType GetSymbolValue() const noexcept;
        [[nodiscard]] IntegerType GetExponent() const noexcept;
        [[nodiscard]] IntegerType GetMantissa() const noexcept;

        [[nodiscard]] NumericalValueSymbol GetSymbol() const noexcept;
        [[nodiscard]] FloatingPointAnalysisType GetType() const noexcept;
        [[nodiscard]] int GetRealExponent() const;
        [[nodiscard]] IntegerType GetRealMantissa() const noexcept;

    private:
        static constexpr IntegerType sm_Symbol{ TraitsType::g_Symbol };
        static constexpr uint32_t sm_SymbolShifting{ TraitsType::g_SymbolShifting };
        static constexpr IntegerType sm_Exponent{ TraitsType::g_Exponent };
        static constexpr uint32_t sm_ExponentShifting{ TraitsType::g_ExponentShifting };
        static constexpr IntegerType sm_MaxExponent{ sm_Exponent >> sm_ExponentShifting };
        static constexpr uint32_t sm_RealExponentDifference{ TraitsType::g_RealExponentDifference };
        static constexpr IntegerType sm_Mantissa{ TraitsType::g_Mantissa };
        static constexpr IntegerType sm_QuietNaN{ TraitsType::g_QuietNaN };

    private:
        T m_Value;
    };
}

#endif  // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
