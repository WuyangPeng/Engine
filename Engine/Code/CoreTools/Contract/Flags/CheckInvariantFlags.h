///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 11:25)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class CheckInvariantConditions
    {
        OnlyPreCondition,  // 仅断言前置条件
        OnlyPostCondition,  // 仅断言后置条件
        Fully  // 完全类不变式
    };

    enum class TriggerAssertCheck
    {
        Invariant,  // 不变式
        Assertion,  // 断言
    };
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_FLAGS_H