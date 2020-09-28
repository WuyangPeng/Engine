//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:35)

#include "System/SystemExport.h"

#include "ConditionVariable.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

void System::InitializeSystemConditionVariable([[maybe_unused]] ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::InitializeConditionVariable(conditionVariable);
#else  // !SYSTEM_PLATFORM_WIN32 

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SleepConditionVariableSlimReaderWriter([[maybe_unused]] ConditionVariablePtr conditionVariable, [[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] ConditionVariableLockMode flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SleepConditionVariableSRW(conditionVariable, slimReaderWriterLock, milliseconds, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SleepConditionVariableCriticalSection([[maybe_unused]] ConditionVariablePtr conditionVariable, [[maybe_unused]] ThreadingCriticalSectionPtr criticalSection, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SleepConditionVariableCS(conditionVariable, criticalSection, milliseconds) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WakeSystemConditionVariable([[maybe_unused]] ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::WakeConditionVariable(conditionVariable);
#else  // !SYSTEM_PLATFORM_WIN32
    
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WakeAllSystemConditionVariable([[maybe_unused]] ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::WakeAllConditionVariable(conditionVariable);
#else  // !SYSTEM_PLATFORM_WIN32
    
#endif  // SYSTEM_PLATFORM_WIN32
}
