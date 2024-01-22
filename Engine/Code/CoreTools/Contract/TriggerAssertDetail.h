/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:37)

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
