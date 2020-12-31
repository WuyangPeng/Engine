//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:02)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H

#include "FormatString.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

template <typename... T>
bool System::StringPrintfUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, const TChar* format, T... args)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (IsFailed(::StringCchPrintf(dest, destCharactersSize, format, args...)))
        return false;
    else
        return true;

#else  // !SYSTEM_PLATFORM_WIN32

    va_list arguments{ nullptr };
    va_start(arguments, format);
    va_end(arguments);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System::StringPrintfUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, const TChar* format, T... args)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (IsFailed(::StringCbPrintf(dest, destBytesSize, format, args...)))
        return false;
    else
        return true;

#else  // !SYSTEM_PLATFORM_WIN32

    va_list arguments{ nullptr };
    va_start(arguments, format);
    va_end(arguments);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System::StringPrintfUseCharactersSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destCharactersSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag, const TChar* format, T... args)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (IsFailed(::StringCchPrintfEx(dest, destCharactersSize, destEnd, remaining, EnumCastUnderlying(flag), format, args...)))
        return false;
    else
        return true;

#else  // !SYSTEM_PLATFORM_WIN32

    va_list arguments{ nullptr };
    va_start(arguments, format);
    va_end(arguments);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename... T>
bool System::StringPrintfUseBytesSize([[maybe_unused]] TChar* dest, [[maybe_unused]] size_t destBytesSize, [[maybe_unused]] TChar** destEnd, [[maybe_unused]] size_t* remaining, [[maybe_unused]] StringSafe flag, const TChar* format, T... args)
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (IsFailed(::StringCbPrintfEx(dest, destBytesSize, destEnd, remaining, EnumCastUnderlying(flag), format, args...)))
        return false;
    else
        return true;

#else  // !SYSTEM_PLATFORM_WIN32

    va_list arguments{ nullptr };
    va_start(arguments, format);
    va_end(arguments);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

template <typename... Types>
int System::SNPrintf(char* const buffer, [[maybe_unused]] const size_t sizeInBytes, const size_t maxCount, char const* const format, const Types&... args) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::_snprintf_s(buffer, sizeInBytes, maxCount, format, args...);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::snprintf(buffer, maxCount, format, args...);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_DETAIL_H
