///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 15:54)

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

    // 返回存储在buffer中的字符，不包括终止null字符。错误返回 -1。
    NODISCARD int SYSTEM_DEFAULT_DECLARE VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    /// 返回存储在buffer中的字符，
    /// 不包括终止null字符。
    /// 传入的sizeInBytes大小包括终止null字符，
    /// buffer的大小至少为sizeInBytes。
    /// 错误返回-1。
    template <typename... Types>
    NODISCARD int SnPrintF(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
