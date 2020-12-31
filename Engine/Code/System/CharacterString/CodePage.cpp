//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:18)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsCodePageValid([[maybe_unused]] CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidCodePage(EnumCastUnderlying(codePage)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32
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

bool System::GetCodePageInfo([[maybe_unused]] CodePage codePage, [[maybe_unused]] CodePageInfoPtr codePageInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCPInfo(EnumCastUnderlying(codePage), codePageInfo) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetCodePageInfo([[maybe_unused]] CodePage codePage, [[maybe_unused]] CodePageInfoExPtr codePageInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetCPInfoEx(EnumCastUnderlying(codePage), 0, codePageInfo) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
