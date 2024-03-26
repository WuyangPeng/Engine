/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:07)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/VariableTemplateType.h"

#include <cstdarg>

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StringCat(char* destination, size_t sizeInBytes, const char* source) noexcept;

    NODISCARD size_t SYSTEM_DEFAULT_DECLARE StringLength(const char* string) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE StringCopy(char* destination, size_t sizeInBytes, char const* source) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE char* StringToken(char* string, char const* delimiter, char** context) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE const char* StringString(char const* string, char const* subString) noexcept;

    /// 返回存储在buffer中的字符，不包括终止null字符。错误返回 -1。
    NODISCARD int SYSTEM_DEFAULT_DECLARE VsnPrintF(char* buffer, size_t size, const char* format, va_list argList) noexcept;

    /// 返回存储在buffer中的字符，
    /// 不包括终止null字符。
    /// 传入的sizeInBytes大小包括终止null字符，
    /// buffer的大小至少为sizeInBytes。
    /// 错误返回-1。
    template <typename... Types>
    NODISCARD int SnPrintF(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept requires(std::is_same_v<typename IsScalar<Types...>::Type, std::true_type>);
    ;
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_H
