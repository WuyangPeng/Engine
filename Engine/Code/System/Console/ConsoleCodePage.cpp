//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:45)

#include "System/SystemExport.h"

#include "ConsoleCodePage.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::CodePage System::GetConsoleCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<CodePage>(::GetConsoleCP());
#else  // !SYSTEM_PLATFORM_WIN32
    return CodePage::UTF8;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleCodePage([[maybe_unused]] CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleCP(EnumCastUnderlying(codePage)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::CodePage System::GetConsoleOutputCodePage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<CodePage>(::GetConsoleOutputCP());
#else  // !SYSTEM_PLATFORM_WIN32
    return CodePage::UTF8;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleOutputCodePage([[maybe_unused]] CodePage codePage) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleOutputCP(EnumCastUnderlying(codePage)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
