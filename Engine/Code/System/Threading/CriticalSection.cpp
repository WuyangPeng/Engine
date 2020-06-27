// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/10 12:03)

#include "System/SystemExport.h"

#if defined(SYSTEM_USING_VC80) && defined(SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION)
	// �鿴������
	// http://msdn.microsoft.com/en-us/library/ms683476(VS.85).aspx��
	// ����Ϊʲô��Щ#definesҪ��InitializeCriticalSectionAndSpinCount�б�¶��
	#define WIN32_LEAN_AND_MEAN
	#define _WIN32_WINNT 0x0500
#endif // CORE_TOOLS_USING_VC80 && SYSTEM_SPIN_COUNT_CRITICAL_SECTION

#include "CriticalSection.h"
#include "Flags/CriticalSectionFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/ExceptionFlags.h"

bool System
	::InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount, CriticalSectionInfo flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

#if (_WIN32_WINNT < 0x0600)

	auto succeed = g_True;

	__try
	{
		::InitializeCriticalSection(criticalSection);

		SetSystemCriticalSectionSpinCount(criticalSection, spinCount);
	}
	__except (EnumCastUnderlying(Exception::ExecuteHandler))
	{
		succeed = g_False;
	}

	SYSTEM_UNUSED_ARG(flags);

	return succeed == g_True;

#else // (0x0600 <= _WIN32_WINNT)

	if (::InitializeCriticalSectionEx(criticalSection, spinCount, EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;

#endif  // (_WIN32_WINNT < 0x0600)

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
	SYSTEM_UNUSED_ARG(spinCount);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::InitializeSystemCriticalSectionAndSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitializeCriticalSectionAndSpinCount(criticalSection, spinCount) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
	SYSTEM_UNUSED_ARG(spinCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#if defined(SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION)
	// ��MSVS2010�ĵ����ᵽ���ѹ������������趨Ϊ��Լ4000�������ǿ����������4096��
	return InitializeSystemCriticalSectionAndSpinCount(criticalSection, 4096);
#else // !SYSTEM_SPIN_COUNT_CRITICAL_SECTION
	return InitializeSystemCriticalSection(criticalSection, 0, CriticalSectionInfo::NoDebugInfo);
#endif // SYSTEM_SPIN_COUNT_CRITICAL_SECTION
}

void System
	::DeleteSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::DeleteCriticalSection(criticalSection);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::EnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::EnterCriticalSection(criticalSection);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::LeaveSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::LeaveCriticalSection(criticalSection);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::TryEnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TryEnterCriticalSection(criticalSection) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::SetSystemCriticalSectionSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetCriticalSectionSpinCount(criticalSection, spinCount);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(criticalSection);
	SYSTEM_UNUSED_ARG(spinCount);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}
