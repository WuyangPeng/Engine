//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:37)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <iosfwd>
#include <string>

namespace CoreTools
{
    template <typename CharT>
    struct CaseInsensitiveStringTraits : public std::char_traits<CharT>
    {
        using ClassType = CaseInsensitiveStringTraits<CharT>;
        using ParentType = std::char_traits<CharT>;
        using CharType = typename ParentType::char_type;

        [[nodiscard]] static bool eq(CharType lhs, CharType rhs) noexcept;
        [[nodiscard]] static bool ne(CharType lhs, CharType rhs) noexcept;
        [[nodiscard]] static bool lt(CharType lhs, CharType rhs) noexcept;
        [[nodiscard]] static int compare(const CharType* lhs, const CharType* rhs, size_t size) noexcept;
        [[nodiscard]] static const CharType* find(const CharType* str, size_t size, CharType character) noexcept;

    private:
        [[nodiscard]] static int DoCompare(const CharType* lhs, const CharType* rhs, size_t size) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
    };

    using CaseInsensitiveCStringTraits = CaseInsensitiveStringTraits<char>;
    using CaseInsensitiveWStringTraits = CaseInsensitiveStringTraits<wchar_t>;
    using CaseInsensitiveTStringTraits = CaseInsensitiveStringTraits<System::TChar>;
    using CaseInsensitiveString = std::basic_string<char, CaseInsensitiveCStringTraits>;
    using CaseInsensitiveWString = std::basic_string<wchar_t, CaseInsensitiveWStringTraits>;
    using CaseInsensitiveTString = std::basic_string<System::TChar, CaseInsensitiveTStringTraits>;

    CORE_TOOLS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const CaseInsensitiveString& str);
    CORE_TOOLS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const CaseInsensitiveWString& str);
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
