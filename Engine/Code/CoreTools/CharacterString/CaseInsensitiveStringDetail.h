// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/19 10:20)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H

#include "CaseInsensitiveString.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <cwctype> 

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>
::eq(CharType lhs, CharType rhs) noexcept
{
	return toupper(lhs) == toupper(rhs);
}

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>
::ne(CharType lhs, CharType rhs) noexcept
{
	return !eq(lhs, rhs);
}

template <typename CharT>
bool CoreTools::CaseInsensitiveStringTraits<CharT>
::lt(CharType lhs, CharType rhs) noexcept
{
	return toupper(lhs) < toupper(rhs);
}

template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>
::compare(const CharType* lhs, const CharType* rhs, size_t size) noexcept
{
	EXCEPTION_TRY
	{
		return DoCompare(lhs,rhs,size);
	}
		EXCEPTION_ALL_CATCH(CoreTools)

		return 0;
}

// private
template <typename CharT>
int CoreTools::CaseInsensitiveStringTraits<CharT>
	::DoCompare(const CharType* lhs, const CharType* rhs, size_t size) noexcept
{
	EXCEPTION_TRY
	{
		#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		for (auto i = 0u; i < size; ++i)
		{
			if (lhs == nullptr)
				return -1;
			else if (rhs == nullptr)
				return 1;
			else if (tolower(*lhs) < tolower(*rhs))
				return -1;
			else if (tolower(*lhs) > tolower(*rhs))
				return 1;
			
			CORE_TOOLS_ASSERTION_2(tolower(*lhs) == tolower(*rhs), "±È½Ï×Ö·û´®·¢Éú´íÎó£¡");
			++lhs;
			++rhs;
		}
#include STSTEM_WARNING_POP
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return 0;
}

template <typename CharT>
typename const CoreTools::CaseInsensitiveStringTraits<CharT>::CharType* CoreTools::CaseInsensitiveStringTraits<CharT>
::find(const CharType* str, size_t size, CharType character) noexcept
{
	while (0 < size--)
	{
		if (toupper(*str) == toupper(character))
			return str;
		else
			++str;
	}

	return nullptr;
}
#include STSTEM_WARNING_POP

#endif // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_DETAIL_H