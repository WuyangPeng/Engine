///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:47)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsCodePageValid(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidCodePage(EnumCastUnderlying(codePage)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetANSICodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetACP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::UTF8;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetOEMCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(::GetOEMCP());

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::UTF8;

#endif  // SYSTEM_PLATFORM_WIN32
}
