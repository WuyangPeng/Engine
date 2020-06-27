// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 21:39)

#include "System/SystemExport.h"

#include "ConsoleTitle.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System
	::GetSystemConsoleTitle(TChar* consoleTitle, WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleTitle(consoleTitle, size);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleTitle);
	SYSTEM_UNUSED_ARG(size);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleOriginalTitle(TChar* consoleTitle, WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleOriginalTitle(consoleTitle, size);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleTitle);
	SYSTEM_UNUSED_ARG(size);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleTitle(const TChar* consoleTitle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleTitle(consoleTitle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleTitle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
