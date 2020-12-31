//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/22 13:17)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "Flags/FormatStringFlags.h"
#include "System/Helper/UnicodeUsing.h"

#include <cstdarg>

namespace System
{
    // ��ʽ���ַ�����

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE VsnPrintf(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE Strcat(char* destination, size_t sizeInBytes, const char* source) noexcept;

    [[nodiscard]] size_t SYSTEM_DEFAULT_DECLARE Strlen(const char* str) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE Strcpy(char* destination, size_t sizeInBytes, char const* source) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE char* Strtok(char* string, char const* delimiter, char** context) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE const char* Strstr(char const* str, char const* subStr) noexcept;

    [[nodiscard]] constexpr StringSafe GetFillByteStringSafe(StringSafe flag) noexcept
    {
        return (flag & StringSafe::FillByte) | StringSafe::FillBehindNull;
    }

    [[nodiscard]] constexpr StringSafe GetFailureByteStringSafe(StringSafe flag) noexcept
    {
        return (flag & StringSafe::FillByte) | StringSafe::FillOnFailure;
    }

    [[nodiscard]] constexpr StringSafe GetFillPatternStringSafe(StringSafe flag) noexcept
    {
        return flag & StringSafe::FillByte;
    }

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t srcCharactersSize,
                                                                          TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCopyUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t srcBytesSize,
                                                                     TChar** destEnd, size_t* remaining, StringSafe flag);

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* src, size_t appendCharactersSize,
                                                                         TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringCatUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* src, size_t appendBytesSize,
                                                                    TChar** destEnd, size_t* remaining, StringSafe flag);

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringGetsUseBytesSize(TChar* dest, size_t destBytesSize);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringGetsUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringGetsUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag);

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringLengthUseCharactersSize(const TChar* src, size_t maxCharactersSize, size_t* charactersLength);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringLengthUseBytesSize(const TChar* src, size_t maxBytesSize, size_t* bytesLength);

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, va_list argList);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, va_list argList);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining,
                                                                             StringSafe flag, const TChar* format, va_list argList);
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE StringVPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining,
                                                                        StringSafe flag, const TChar* format, va_list argList);

    template <typename... T>
    [[nodiscard]] bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, const TChar* format, T... args);
    template <typename... T>
    [[nodiscard]] bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, const TChar* format, T... args);
    template <typename... T>
    [[nodiscard]] bool StringPrintfUseCharactersSize(TChar* dest, size_t destCharactersSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args);
    template <typename... T>
    [[nodiscard]] bool StringPrintfUseBytesSize(TChar* dest, size_t destBytesSize, TChar** destEnd, size_t* remaining, StringSafe flag, const TChar* format, T... args);

    // ���ش洢��buffer�е��ַ�����������ֹnull�ַ���
    // �����sizeInBytes��С������ֹnull�ַ���buffer�Ĵ�С����ΪsizeInBytes�����󷵻�-1��

    template <typename... Types>
    [[nodiscard]] int SNPrintf(char* const buffer, const size_t sizeInBytes, const size_t maxCount, char const* const format, const Types&... args) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
