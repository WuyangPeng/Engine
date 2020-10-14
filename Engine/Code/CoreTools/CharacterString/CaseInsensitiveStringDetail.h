//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:37)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H

#include "CaseInsensitiveString.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <cwctype>

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::eq(CharType lhs, CharType rhs) noexcept
{
    return toupper(lhs) == toupper(rhs);
}

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::ne(CharType lhs, CharType rhs) noexcept
{
    return !eq(lhs, rhs);
}

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::lt(CharType lhs, CharType rhs) noexcept
{
    return toupper(lhs) < toupper(rhs);
}

template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::compare(const CharType* lhs, const CharType* rhs, size_t size) noexcept
{
    EXCEPTION_TRY
    {
        return DoCompare(lhs, rhs, size);
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return 0;
}

// private
template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::DoCompare(const CharType* lhs, const CharType* rhs, size_t size) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    for (auto i = 0u; i < size; ++i)
    {
        if (lhs == nullptr)
            return -1;
        else if (rhs == nullptr)
            return 1;
        else if (tolower(*lhs) < tolower(*rhs))
            return -1;
        else if (tolower(*rhs) < tolower(*lhs))
            return 1;

        CORE_TOOLS_ASSERTION_2(tolower(*lhs) == tolower(*rhs), "比较字符串发生错误！");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        ++lhs;
        ++rhs;
#include STSTEM_WARNING_POP
    }

    return 0;
}

template <typename CharT>
typename const CoreTools::CaseInsensitiveStringTraits<CharT>::CharType* CoreTools::CaseInsensitiveStringTraits<CharT>::find(const CharType* str, size_t size, CharType character) noexcept
{
    while (0 < size--)
    {
        if (toupper(*str) == toupper(character))
        {
            return str;
        }
        else
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ++str;
#include STSTEM_WARNING_POP
        }
    }

    return nullptr;
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H