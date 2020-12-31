///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 13:17)

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
}

#endif  // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
