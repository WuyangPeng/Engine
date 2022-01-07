///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 22:46)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <cstdarg>

namespace System
{
    // ��ʽ���ַ�����

    NODISCARD int SYSTEM_DEFAULT_DECLARE VsnPrintf(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE Strcat(char* destination, size_t sizeInBytes, const char* source) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE Strlen(const char* str) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE char* Strtok(char* string, char const* delimiter, char** context) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE const char* Strstr(char const* str, char const* subStr) noexcept;

    // ���ش洢��buffer�е��ַ�����������ֹnull�ַ���
    // �����sizeInBytes��С������ֹnull�ַ���buffer�Ĵ�С����ΪsizeInBytes�����󷵻�-1��

    template <typename... Types>
    NODISCARD int SNPrintf(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
