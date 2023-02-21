///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:07)

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
bool CoreTools::CaseInsensitiveStringTraits<CharT>::lt(CharType lhs, CharType rhs) noexcept
{
    return toupper(lhs) < toupper(rhs);
}

template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::compare(const CharType* lhs, const CharType* rhs, size_t count) noexcept
{
    EXCEPTION_TRY
    {
        return DoCompare(lhs, rhs, count);
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return 0;
}

// private
template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>::DoCompare(const CharType* lhs, const CharType* rhs, size_t count) noexcept(gAssert < 2 || gCoreToolsAssert < 2)
{
    for (auto i = 0u; i < count; ++i)
    {
        if (lhs == nullptr)
        {
            return -1;
        }
        else if (rhs == nullptr)
        {
            return 1;
        }
        else
        {
            const auto lhsLower = tolower(*lhs);
            const auto rhsLower = tolower(*rhs);

            if (lhsLower < rhsLower)
                return -1;
            else if (rhsLower < lhsLower)
                return 1;

            CORE_TOOLS_ASSERTION_2(lhsLower == rhsLower, "比较字符串发生错误！");
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ++lhs;
        ++rhs;

#include STSTEM_WARNING_POP
    }

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        ++first;
#include STSTEM_WARNING_POP
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