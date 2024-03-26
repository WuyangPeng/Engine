/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:58)

#include "System/SystemExport.h"

#include "ConsoleCodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

System::CodePage System::GetConsoleCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(gsl::narrow_cast<int>(::GetConsoleCP()));

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetConsoleCP(EnumCastUnderlying(codePage)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetConsoleOutputCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<CodePage>(gsl::narrow_cast<int>(::GetConsoleOutputCP()));

#else  // !SYSTEM_PLATFORM_WIN32

    return CodePage::Utf8;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleOutputCodePage(CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetConsoleOutputCP(EnumCastUnderlying(codePage)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(codePage);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
