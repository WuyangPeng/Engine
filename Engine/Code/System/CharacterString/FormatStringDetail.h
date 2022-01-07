///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:27)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H

#include "FormatString.h"
#include "System/Helper/VariableTemplateType.h"

template <typename... Types>
int System::SNPrintf(char* buffer, size_t sizeInBytes, MAYBE_UNUSED size_t maxCount, const char* format, Types... args) noexcept
{
    static_assert(std::is_same_v<IsScalar<Types...>::Type, std::true_type>);

#ifdef SYSTEM_PLATFORM_WIN32

    return ::_snprintf_s(buffer, sizeInBytes, maxCount, format, args...);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::snprintf(buffer, sizeInBytes, format, args...);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H
