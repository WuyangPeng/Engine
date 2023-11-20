///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:21)

#include "System/SystemExport.h"

#include "ConsoleCodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

System::CodePage System::GetConsoleCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetConsoleCP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleCP(EnumCastUnderlying(codePage)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetConsoleOutputCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetConsoleOutputCP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleOutputCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleOutputCP(EnumCastUnderlying(codePage)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
