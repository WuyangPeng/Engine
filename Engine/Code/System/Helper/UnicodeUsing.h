//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:33)

#ifndef SYSTEM_HELPER_UNICODE_MACRO_H
#define SYSTEM_HELPER_UNICODE_MACRO_H

// Unicode字符和ANSI字符所需要的using声明和宏

#include "ConfigMacro.h"

#include <iosfwd>
#include <string>

namespace System
{
#ifdef UNICODE

    using String = std::wstring;
    using StringStream = std::wstringstream;
    using OStringStream = std::wostringstream;
    using IStringStream = std::wistringstream;
    using FileStream = std::wfstream;
    using OFileStream = std::wofstream;
    using IFileStream = std::wifstream;
    using Stream = std::wiostream;
    using OStream = std::wostream;
    using IStream = std::wistream;
    using TChar = wchar_t;

#else  // !UNICODE

    using String = std::string;
    using StringStream = std::stringstream;
    using OStringStream = std::ostringstream;
    using IStringStream = std::istringstream;
    using FileStream = std::fstream;
    using OFileStream = std::ofstream;
    using IFileStream = std::ifstream;
    using Stream = std::iostream;
    using OStream = std::ostream;
    using IStream = std::istream;
    using TChar = char;

#endif  // UNICODE

    template <typename T>
    String ToString(const T value)
    {
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

#endif  // SYSTEM_HELPER_UNICODE_MACRO_H
