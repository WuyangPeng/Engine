///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:22)

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
