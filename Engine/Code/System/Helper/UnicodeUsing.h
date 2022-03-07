///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 17:49)

#ifndef SYSTEM_HELPER_UNICODE_MACRO_H
#define SYSTEM_HELPER_UNICODE_MACRO_H

// Unicode字符和ANSI字符所需要的using声明和宏

#include "ConfigMacro.h"

#include <iosfwd>
#include <regex>
#include <string>

namespace System
{
#ifdef UNICODE

    using TChar = wchar_t;
    using String = std::wstring;
    using StringView = std::wstring_view;
    using StringStream = std::wstringstream;
    using OStringStream = std::wostringstream;
    using IStringStream = std::wistringstream;
    using FileStream = std::wfstream;
    using OFileStream = std::wofstream;
    using IFileStream = std::wifstream;
    using Stream = std::wiostream;
    using OStream = std::wostream;
    using IStream = std::wistream;
    using Regex = std::wregex;

#else  // !UNICODE

    using TChar = char;
    using String = std::string;
    using StringView = std::string_view;
    using StringStream = std::stringstream;
    using OStringStream = std::ostringstream;
    using IStringStream = std::istringstream;
    using FileStream = std::fstream;
    using OFileStream = std::ofstream;
    using IFileStream = std::ifstream;
    using Stream = std::iostream;
    using OStream = std::ostream;
    using IStream = std::istream;
    using Regex = std::regex;

#endif  // UNICODE

    template <typename T>
    String ToString(const T value)
    {
        static_assert(std::is_arithmetic_v<T>);

#ifdef UNICODE
        return std::to_wstring(value);
#else  // !UNICODE
        return std::to_string(value);
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
}

#endif  // SYSTEM_HELPER_UNICODE_MACRO_H
