///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:01)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H
#define SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ConditionVariableLockMode
    {
        Exclusive = 0x0,
        Shared = CONDITION_VARIABLE_LOCKMODE_SHARED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ConditionVariableLockMode
    {
        Exclusive = 0x0,
        Shared = 0x1,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H