///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:16)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <vector>

namespace Mathematics
{
    // N������ҪԪ������32λ�ֽڵ���Ŀ��
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

        // �������¡�
        IntegerDataOperator& operator+=(const IntegerData& rhs);
        IntegerDataOperator& operator-=(const IntegerData& rhs);
        IntegerDataOperator& operator*=(const IntegerData& rhs);

        // ���Ҫͬʱ����̺�������
        // ֱ�ӵ���IntegerDataAnalysis::GetDivisionModulo
        IntegerDataOperator& operator/=(const IntegerData& rhs);
        IntegerDataOperator& operator%=(const IntegerData& rhs);

        // ��λ���¡�
        IntegerDataOperator& operator<<=(int shift);
        IntegerDataOperator& operator>>=(int shift);

    private:
        static constexpr auto sm_IntSize = 2 * N;
        static constexpr auto sm_IntLast = sm_IntSize - 1;
        static constexpr auto sm_Carry = 0x00010000u;
        static constexpr auto sm_Low = 0x0000FFFFu;
        static constexpr auto sm_High = 0xFFFF0000u;
        static constexpr uint16_t sm_Symbol{ 0x8000 };
        static constexpr auto sm_Positive = 0xFFFFFFFFu;

        IntegerData& m_Master;
        IntegerDataAmend m_Amend;
        IntegerDataAnalysis m_Analysis;
    };

    template <int N>
    [[nodiscard]] IntegerData<N> operator+(const IntegerData<N>& lhs, const IntegerData<N>& rhs);

    template <int N>
    [[nodiscard]] IntegerData<N> operator-(const IntegerData<N>& lhs, const IntegerData<N>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_OPERATOR_H
