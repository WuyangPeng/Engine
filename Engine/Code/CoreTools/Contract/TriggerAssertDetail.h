///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 13:36)

#ifndef CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_DETAIL_H
#define CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_DETAIL_H

#include "TriggerAssert.h"
#include "System/Helper/PragmaWarning/Format.h"

template <typename... Types>
CoreTools::TriggerAssert::TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const std::string& message, Types&&... arguments)
    : triggerAssertCheck{ triggerAssertCheck }
{
    Format format{ message };

    Process(functionDescribed, format, std::forward<Types>(arguments)...);
}

template <typename Type, typename... Types>
void CoreTools::TriggerAssert::Process(const FunctionDescribed& functionDescribed, Format& format, Type&& argument, Types&&... arguments)
{
    format % argument;

    Process(functionDescribed, format, std::forward<Types>(arguments)...);
}

#endif  // CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_DETAIL_H
