///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/03/31 18:23)

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

    NullFunction<CodePage>(codePage);

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


