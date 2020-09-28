//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:42)

#include "System/SystemExport.h"

#include "ConsoleAlias.h"
#include "System/Helper/WindowsMacro.h"

bool System::AddSystemConsoleAlias([[maybe_unused]] TChar* source, [[maybe_unused]] TChar* target, [[maybe_unused]] TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AddConsoleAlias(source, target, exeName) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleAlias([[maybe_unused]] TChar* source, [[maybe_unused]] TChar* targetBuffer, [[maybe_unused]] WindowDWord targetBufferLength, [[maybe_unused]] TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleAlias(source, targetBuffer, targetBufferLength, exeName);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleAliasesLength([[maybe_unused]] TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleAliasesLength(exeName);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleAliasExesLength() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleAliasExesLength();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleAliases([[maybe_unused]] TChar* aliasBuffer, [[maybe_unused]] WindowDWord aliasBufferLength, [[maybe_unused]] TChar* exeName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleAliases(aliasBuffer, aliasBufferLength, exeName);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleAliasExes([[maybe_unused]] TChar* exeNameBuffer, [[maybe_unused]] WindowDWord exeNameBufferLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleAliasExes(exeNameBuffer, exeNameBufferLength);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}
