///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:51)

#ifndef MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
#define MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H

#include "System/Helper/EnumOperator.h"

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
}

#endif  // MATHEMATICS_BASE_NUMERICAL_VALUE_SYMBOL_H
