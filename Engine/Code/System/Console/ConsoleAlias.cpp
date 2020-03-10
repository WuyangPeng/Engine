// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:36)

#include "System/SystemExport.h"

#include "ConsoleAlias.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::AddSystemConsoleAlias(TChar* source, TChar* target, TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AddConsoleAlias(source, target, exeName) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleAlias(TChar* source, TChar* targetBuffer, WindowDWord targetBufferLength, TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleAlias(source, targetBuffer, targetBufferLength, exeName);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleAliasesLength(TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleAliasesLength(exeName);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleAliasExesLength() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleAliasExesLength();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleAliases(TChar* aliasBuffer, WindowDWord aliasBufferLength, TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleAliases(aliasBuffer, aliasBufferLength, exeName);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemConsoleAliasExes(TChar* exeNameBuffer, WindowDWord exeNameBufferLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetConsoleAliasExes(exeNameBuffer, exeNameBufferLength);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}
