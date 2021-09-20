///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/29 17:27)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <iosfwd>
#include <string>

namespace CoreTools
{
    template <typename CharT>
    class CaseInsensitiveStringTraits final : public std::char_traits<CharT>
    {
    public:
        using ClassType = CaseInsensitiveStringTraits<CharT>;
        using ParentType = std::char_traits<CharT>;
        using CharType = typename ParentType::char_type;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static bool eq(CharType lhs, CharType rhs) noexcept;
        NODISCARD static bool lt(CharType lhs, CharType rhs) noexcept;
        NODISCARD static int compare(const CharType* lhs, const CharType* rhs, size_t count) noexcept;
        NODISCARD static const CharType* find(const CharType* first, size_t count, CharType character) noexcept;

    private:
        NODISCARD static int DoCompare(const CharType* lhs, const CharType* rhs, size_t count) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
    };

    using CaseInsensitiveCStringTraits = CaseInsensitiveStringTraits<char>;
    using CaseInsensitiveWStringTraits = CaseInsensitiveStringTraits<wchar_t>;
    using CaseInsensitiveTStringTraits = CaseInsensitiveStringTraits<System::TChar>;
    using CaseInsensitiveDynamicLinkStringTraits = CaseInsensitiveStringTraits<System::DynamicLinkCharType>;
    using CaseInsensitiveString = std::basic_string<char, CaseInsensitiveCStringTraits>;
    using CaseInsensitiveWString = std::basic_string<wchar_t, CaseInsensitiveWStringTraits>;
    using CaseInsensitiveTString = std::basic_string<System::TChar, CaseInsensitiveTStringTraits>;
    using CaseInsensitiveDynamicLinkString = std::basic_string<System::DynamicLinkCharType, CaseInsensitiveDynamicLinkStringTraits>;

    CORE_TOOLS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const CaseInsensitiveString& str);
    CORE_TOOLS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const CaseInsensitiveWString& str);
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
