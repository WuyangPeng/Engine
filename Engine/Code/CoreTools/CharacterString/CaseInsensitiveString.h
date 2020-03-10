// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:22)

#ifndef CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
#define CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <iosfwd>

namespace CoreTools
{
	template <typename CharT>
	struct CaseInsensitiveStringTraits : public std::char_traits<CharT>
	{
		using ClassType = CaseInsensitiveStringTraits<CharT>;
		using ParentType = std::char_traits<CharT>;
		using CharType = typename ParentType::char_type;

		static bool eq(CharType lhs, CharType rhs) noexcept;
		static bool ne(CharType lhs, CharType rhs) noexcept;
		static bool lt(CharType lhs, CharType rhs) noexcept;
		static int compare(const CharType* lhs, const CharType* rhs, size_t size) noexcept;
		static const CharType* find(const CharType* str, size_t size, CharType character) noexcept;

	private:
		static int DoCompare(const CharType* lhs, const CharType* rhs, size_t size) noexcept;
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

#endif // CORE_TOOLS_CHARACTER_STRING_CASE_INSENSITIVE_STRING_H
