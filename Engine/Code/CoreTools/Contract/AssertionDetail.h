///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:43)

#ifndef CORE_TOOLS_CONTRACT_ASSERTION_DETAIL_H
#define CORE_TOOLS_CONTRACT_ASSERTION_DETAIL_H

#include "Assertion.h"
#include "TriggerAssertDetail.h"
#include "Flags/CheckInvariantFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename... Types>
CoreTools::Assertion::Assertion(bool condition, const FunctionDescribed& functionDescribed, const char* format, Types&&... arguments)
{
    if (!condition)
    {
        const TriggerAssert triggerAssert{ TriggerAssertCheck::Assertion, functionDescribed, format, std::forward<Types>(arguments)... };
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#endif  // CORE_TOOLS_CONTRACT_ASSERTION_DETAIL_H
