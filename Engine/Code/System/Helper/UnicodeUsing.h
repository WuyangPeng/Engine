///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/16 14:58)

#ifndef SYSTEM_HELPER_UNICODE_MACRO_H
#define SYSTEM_HELPER_UNICODE_MACRO_H

// Unicode�ַ���ANSI�ַ�����Ҫ��using�����ͺ�

#include "ConfigMacro.h"

#include <iosfwd>
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

namespace System
{
    constexpr auto nullChar = SYSTEM_TEXT('\0');
}

#endif  // SYSTEM_HELPER_UNICODE_MACRO_H
