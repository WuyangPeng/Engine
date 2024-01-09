/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:25)

#include "System/SystemExport.h"

#include "FormatString.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdio>
#include <cstring>

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

int System::VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept

#include SYSTEM_WARNING_POP
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_vsnprintf_s(buffer, size, _TRUNCATE, format, argList);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::vsnprintf(buffer, size, format, argList);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StrCat(char* destination, size_t sizeInBytes, const char* source) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    // 如果成功，则为零；如果失败，则为错误代码。
    if (::strcat_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    if (::strcat(destination, source) == 0)
        return true;
    else
        return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

size_t System::StrLen(const char* str) noexcept
{
    if (str != nullptr)
        return ::strlen(str);
    else
        return 0;
}

bool System::StrCpy(char* destination, size_t sizeInBytes, char const* source) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::strcpy_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    if (::strcpy(destination, source) == 0)
        return true;
    else
        return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

char* System::StrTok(char* string, char const* delimiter, char** context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::strtok_s(string, delimiter, context);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::strtok_r(string, delimiter, context);

#endif  // SYSTEM_PLATFORM_WIN32
}

const char* System::StrStr(char const* str, char const* subStr) noexcept
{
    return ::strstr(str, subStr);
}
