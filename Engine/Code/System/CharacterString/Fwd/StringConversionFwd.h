// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:17)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FWD_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FWD_H 

#include "CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
	int MultiByteConversionWideChar(CodePage codePage, MultiByte flag, const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int WideCharConversionMultiByte(CodePage codePage, WideChar flag, const wchar_t* wideChar, int wideCharLength,
									char* multiByte, int multiByteLength, const char* defaultChar, bool* usedDefaultChar) noexcept;

	int MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int UTF8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;
	int WideCharConversionUTF8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;

	ComparesStringReturn CompareStringUseLocale(LanguageLocale locale, Compares comparesFlag, const TChar* lhsString,
												int lhsCount, const TChar* rhsString, int rhsCount) noexcept;

	ComparesStringReturn CompareStringUseLocale(const wchar_t* localeName, Compares comparesFlag, const wchar_t* lhsString,
												int lhsCount, const wchar_t* rhsString, int rhsCount) noexcept;

	ComparesStringReturn CompareStringOrdinalUseBinary(const wchar_t* lhsString, int lhsCount, const wchar_t* rhsString, int rhsCount, bool ignoreCase) noexcept;

	int	FoldStringUseMapping(LocaleIndependentMapping mapFlag, const TChar* src, int srcCount, TChar* dest, int destCount) noexcept;

	bool GetStringTypeUseCharacterType(LanguageLocale locale, CharacterType infoType, const TChar* src, int srcCount, WindowWordPtr charType) noexcept;
}

#endif // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_FWD_H