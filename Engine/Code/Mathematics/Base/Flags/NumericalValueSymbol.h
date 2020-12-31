///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:17)

#ifndef MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
#define MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{
    enum class NumericalValueSymbol
    {
        // 负号
        Negative = -1,
        // 零
        Zero = 0,
        // 正号
        Positive = 1
    };

    ENUM_NEGATE_OPERATOR_DEFINE(NumericalValueSymbol);
    ENUM_MULTIPLICATION_OPERATOR_DEFINE(NumericalValueSymbol);
}

#endif  // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
