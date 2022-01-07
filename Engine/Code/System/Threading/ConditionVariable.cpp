///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 18:11)

#include "System/SystemExport.h"

#include "ConditionVariable.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

void System::InitializeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::InitializeConditionVariable(conditionVariable);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(conditionVariable);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SleepConditionVariableSlimReaderWriter(ConditionVariablePtr conditionVariable, SlimReaderWriterLockPtr slimReaderWriterLock, WindowsDWord milliseconds, ConditionVariableLockMode flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SleepConditionVariableSRW(conditionVariable, slimReaderWriterLock, milliseconds, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(conditionVariable slimReaderWriterLock, milliseconds, flags);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SleepConditionVariableCriticalSection(ConditionVariablePtr conditionVariable, ThreadingCriticalSectionPtr criticalSection, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SleepConditionVariableCS(conditionVariable, criticalSection, milliseconds) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(conditionVariable criticalSection, milliseconds);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WakeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::WakeConditionVariable(conditionVariable);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(conditionVariable);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WakeAllSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::WakeAllConditionVariable(conditionVariable);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(conditionVariable);

#endif  // SYSTEM_PLATFORM_WIN32
}
