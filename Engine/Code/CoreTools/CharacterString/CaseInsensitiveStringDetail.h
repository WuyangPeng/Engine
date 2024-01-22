/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:18)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H

#include "CaseInsensitiveString.h"
#include "System/Helper/PragmaWarning.h"

#include <cwctype>

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::eq(CharType lhs, CharType rhs) noexcept
{
    return toupper(lhs) == toupper(rhs);
}

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::lt(CharType lhs, CharType rhs) noexcept
{
    return toupper(lhs) < toupper(rhs);
}

template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::ToLower(const CharType* value) noexcept
{
    if (value != nullptr)
    {
        return tolower(*value);
    }
    else
    {
        return -1;
    }
}

template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::compare(const CharType* lhs, const CharType* rhs, size_t count) noexcept
{
    for (auto i = 0u; i < count; ++i)
    {
        const auto result = Compare(lhs, rhs);

        if (result != 0)
        {
            return result;
        }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ++lhs;
        ++rhs;

#include SYSTEM_WARNING_POP
    }

    return 0;
}
template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::Compare(const CharType* lhs, const CharType* rhs) noexcept
{
    const auto lhsLower = ToLower(lhs);
    const auto rhsLower = ToLower(rhs);

    if (lhsLower < rhsLower)
        return -1;
    else if (rhsLower < lhsLower)
        return 1;
    else
        return 0;
}

template <typename CharT>
const typename CoreTools::CaseInsensitiveStringTraits<CharT>::CharType* CoreTools::CaseInsensitiveStringTraits<CharT>::find(const CharType* first, size_t count, CharType character) noexcept
{
    const auto lowerCharacter = tolower(character);
    for (auto i = 0u; i < count; ++i)
    {
        if (tolower(*first) == lowerCharacter)
        {
            return first;
        }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ++first;

#include SYSTEM_WARNING_POP
    }

    return nullptr;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H