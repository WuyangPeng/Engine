///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 15:55)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsCodePageValid(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidCodePage(EnumCastUnderlying(codePage)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetAnsiCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetACP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetOemCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetOEMCP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}
