/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:21)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_DETAIL_H
#define SYSTEM_CHARACTER_STRING_FORMAT_DETAIL_H

#include "FormatString.h"
#include "System/Helper/Tools.h"
#include "System/Helper/VariableTemplateType.h"

template <typename... Types>
int System::SnPrintF(char* buffer, size_t sizeInBytes, size_t maxCount, const char* format, Types... args) noexcept
{
    static_assert(std::is_same_v<typename IsScalar<Types...>::Type, std::true_type>);

#ifdef SYSTEM_PLATFORM_WIN32

    return ::_snprintf_s(buffer, sizeInBytes, maxCount, format, args...);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(maxCount);

    return ::snprintf(buffer, sizeInBytes, format, args...);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_DETAIL_H
