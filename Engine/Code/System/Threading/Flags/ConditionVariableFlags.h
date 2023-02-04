///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 12:58)

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