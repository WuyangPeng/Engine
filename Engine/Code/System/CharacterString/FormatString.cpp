///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 15:56)

#include "System/SystemExport.h"

#include "FormatString.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdio>
#include <cstring>

int System::VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_vsnprintf_s(buffer, size, _TRUNCATE, format, argList);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::vsnprintf(buffer, size, format, argList);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::StrCat(char* destination, size_t sizeInBytes, const char* source) noexcept
{
    // ����ɹ�����Ϊ�㣻���ʧ�ܣ���Ϊ������롣
    if (::strcat_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;
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
    if (::strcpy_s(destination, sizeInBytes, source) == 0)
        return true;
    else
        return false;
}

char* System::StrTok(char* string, char const* delimiter, char** context) noexcept
{
    return ::strtok_s(string, delimiter, context);
}

const char* System::StrStr(char const* str, char const* subStr) noexcept
{
    return ::strstr(str, subStr);
}
