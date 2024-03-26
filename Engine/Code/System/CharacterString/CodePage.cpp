/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:08)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

bool System::IsCodePageValid(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::IsValidCodePage(EnumCastUnderlying(codePage)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetAnsiCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(gsl::narrow_cast<int>(::GetACP()));

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetOemCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(gsl::narrow_cast<int>(::GetOEMCP()));

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}
