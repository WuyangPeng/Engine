//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 14:30)

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