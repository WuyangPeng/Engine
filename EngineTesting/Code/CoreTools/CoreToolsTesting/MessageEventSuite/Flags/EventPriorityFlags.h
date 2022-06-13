///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:15)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace CoreTools
{
    enum class EventPriority : uint32_t
    {
        Low,
        Medium,
        High,
    };

    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(EventPriority);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H