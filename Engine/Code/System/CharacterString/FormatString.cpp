/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:09)

#include "System/SystemExport.h"

#include "FormatString.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdio>
#include <cstring>

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

int System::VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_vsnprintf_s(buffer, size, _TRUNCATE, format, argList);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::vsnprintf(buffer, size, format, argList);

#endif  // SYSTEM_PLATFORM_WIN32
}

#include SYSTEM_WARNING_POP

bool System::StringCat(char* destination, size_t sizeInBytes, const char* source) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    /// 如果成功，则为零；如果失败，则为错误代码。
    return ::strcat_s(destination, sizeInBytes, source) == 0;

#else  // !SYSTEM_PLATFORM_WIN32

    return ::strcat(destination, source) == 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

size_t System::StringLength(const char* string) noexcept
{
    if (string != nullptr)
    {
        return ::strlen(string);
    }
    else
    {
        return 0;
    }
}

bool System::StringCopy(char* destination, size_t sizeInBytes, char const* source) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::strcpy_s(destination, sizeInBytes, source) == 0;

#else  // !SYSTEM_PLATFORM_WIN32

    return ::strcpy(destination, source) == 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

char* System::StringToken(char* string, char const* delimiter, char** context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::strtok_s(string, delimiter, context);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::strtok_r(string, delimiter, context);

#endif  // SYSTEM_PLATFORM_WIN32
}

const char* System::StringString(char const* string, char const* subString) noexcept
{
    return ::strstr(string, subString);
}
