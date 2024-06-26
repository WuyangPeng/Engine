/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 22:55)

#ifndef SYSTEM_HELPER_UNICODE_USING_H
#define SYSTEM_HELPER_UNICODE_USING_H

/// Unicode字符和ANSI字符所需要的using声明和宏

#include "ConfigMacro.h"
#include "EnumCast.h"

#include <iosfwd>
#include <regex>
#include <string>

namespace System
{
#ifdef UNICODE

    using TChar = wchar_t;
    using String = std::wstring;
    using StringView = std::wstring_view;
    using Regex = std::wregex;

    using StringStream = std::wstringstream;
    using OStringStream = std::wostringstream;
    using IStringStream = std::wistringstream;
    using FileStream = std::wfstream;
    using OFileStream = std::wofstream;
    using IFileStream = std::wifstream;
    using Stream = std::wiostream;
    using OStream = std::wostream;
    using IStream = std::wistream;

#else  // !UNICODE

    using TChar = char;
    using String = std::string;
    using StringView = std::string_view;
    using Regex = std::regex;

    using StringStream = std::stringstream;
    using OStringStream = std::ostringstream;
    using IStringStream = std::istringstream;
    using FileStream = std::fstream;
    using OFileStream = std::ofstream;
    using IFileStream = std::ifstream;
    using Stream = std::iostream;
    using OStream = std::ostream;
    using IStream = std::istream;

#endif  // UNICODE

    template <typename T>
    requires(std::is_arithmetic_v<T>)
    NODISCARD String ToString(const T value)
    {
#ifdef UNICODE

        return std::to_wstring(value);

#else  // !UNICODE

        return std::to_string(value);

#endif  // UNICODE
    }

    template <typename T>
    requires(std::is_enum_v<T>)
    NODISCARD String ToString(const T value)
    {
#ifdef UNICODE

        return std::to_wstring(EnumCastUnderlying(value));

#else  // !UNICODE

        return std::to_string(EnumCastUnderlying(value));

#endif  // UNICODE
    }
}

#ifdef UNICODE

    #define COUT std::wcout
    #define CIN std::wcin
    #define CERR std::wcerr
    #define CLOG std::wclog
    #define SYSTEM_TEXT(quote) SYSTEM_CONCATENATOR(L, quote)

#else  // !UNICODE

    #define COUT std::cout
    #define CIN std::cin
    #define CERR std::cerr
    #define CLOG std::clog
    #define SYSTEM_TEXT(quote) quote

#endif  // UNICODE

namespace System
{
    constexpr auto nullChar = SYSTEM_TEXT('\0');

    constexpr auto defaultBufferSize = 256;
    using CharBufferType = std::array<char, defaultBufferSize>;
    using WCharBufferType = std::array<wchar_t, defaultBufferSize>;
    using TCharBufferType = std::array<TChar, defaultBufferSize>;
}

#endif  // SYSTEM_HELPER_UNICODE_USING_H
