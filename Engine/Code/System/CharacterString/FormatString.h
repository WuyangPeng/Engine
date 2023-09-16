///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 15:54)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <cstdarg>

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StrCat(char* destination, size_t sizeInBytes, const char* source) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE StrLen(const char* str) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StrCpy(char* destination, size_t sizeInBytes, char const* source) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE char* StrTok(char* string, char const* delimiter, char** context) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE const char* StrStr(char const* str, char const* subStr) noexcept;

    // ���ش洢��buffer�е��ַ�����������ֹnull�ַ������󷵻� -1��
    NODISCARD int SYSTEM_DEFAULT_DECLARE VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    /// ���ش洢��buffer�е��ַ���
    /// ��������ֹnull�ַ���
    /// �����sizeInBytes��С������ֹnull�ַ���
    /// buffer�Ĵ�С����ΪsizeInBytes��
    /// ���󷵻�-1��
    template <typename... Types>
    NODISCARD int SnPrintF(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
