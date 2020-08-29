//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/23 23:39)

#ifndef MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
#define MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{
    enum class NumericalValueSymbol
    {
        // ����
        Negative = -1,
        // ��
        Zero = 0,
        // ����
        Positive = 1
    };

    ENUM_NEGATE_OPERATOR_DEFINE(NumericalValueSymbol);
    ENUM_MULTIPLICATION_OPERATOR_DEFINE(NumericalValueSymbol);

    template <typename T>
    constexpr T operator*(T lhs, Mathematics::NumericalValueSymbol rhs) noexcept
    {
        return rhs * lhs;
    }
}

#endif  // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
