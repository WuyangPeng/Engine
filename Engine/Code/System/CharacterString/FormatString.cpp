///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/13 10:45)

#include "System/SystemExport.h"

#include "FormatString.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdio>
#include <cstring>

int System::VsnPrintf(char* buffer, size_t size, const char* format, va_list argList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_vsnprintf_s(buffer, size, _TRUNCATE, format, argList);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::vsnprintf(buffer, size, format, argList);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Strcat(char* destination, size_t sizeInBytes, const char* source) noexcept
{
    // 如果成功，则为零；如果失败，则为错误代码。
    if (::strcat_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;
}

size_t System::Strlen(const char* str) noexcept
{
    if (str != nullptr)
        return ::strlen(str);
    else
        return 0;
}

bool System::Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept
{
    if (::strcpy_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;
}

char* System::Strtok(char* string, char const* delimiter, char** context) noexcept
{
    return ::strtok_s(string, delimiter, context);
}

const char* System::Strstr(char const* str, char const* subStr) noexcept
{
    return ::strstr(str, subStr);
}
