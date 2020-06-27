// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:35)

#include "System/SystemExport.h"

#include "ConditionVariable.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

void System
	::InitializeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::InitializeConditionVariable(conditionVariable);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(conditionVariable);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SleepConditionVariableSlimReaderWriter(ConditionVariablePtr conditionVariable, SlimReaderWriterLockPtr slimReaderWriterLock, WindowDWord milliseconds, ConditionVariableLockMode flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SleepConditionVariableSRW(conditionVariable, slimReaderWriterLock, milliseconds, EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(conditionVariable);
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SleepConditionVariableCriticalSection(ConditionVariablePtr conditionVariable, ThreadingCriticalSectionPtr criticalSection, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SleepConditionVariableCS(conditionVariable, criticalSection, milliseconds) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(conditionVariable);
	SYSTEM_UNUSED_ARG(criticalSection);
	SYSTEM_UNUSED_ARG(milliseconds);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WakeSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::WakeConditionVariable(conditionVariable);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(conditionVariable);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WakeAllSystemConditionVariable(ConditionVariablePtr conditionVariable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::WakeAllConditionVariable(conditionVariable);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(conditionVariable);
#endif // SYSTEM_PLATFORM_WIN32
}
