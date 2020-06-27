// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.2.0.0 (2020/05/09 16:05)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// ×Ö·û´®×ª»»

	int SYSTEM_DEFAULT_DECLARE MultiByteConversionWideChar(CodePage codePage, MultiByte flag, const char* multiByte,
														   int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int SYSTEM_DEFAULT_DECLARE WideCharConversionMultiByte(CodePage codePage, WideChar flag, const wchar_t* wideChar, int wideCharLength,
														   char* multiByte, int multiByteLength, const char* defaultChar, bool* usedDefaultChar) noexcept;

	int SYSTEM_DEFAULT_DECLARE MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int SYSTEM_DEFAULT_DECLARE UTF8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
	int SYSTEM_DEFAULT_DECLARE WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;
	int SYSTEM_DEFAULT_DECLARE WideCharConversionUTF8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;

	// lhsCountºÍrhsCount²»°üÀ¨¿ÕÖÕÖ¹·û
	ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(LanguageLocale locale, Compares comparesFlag, const TChar* lhsString,
																	   int lhsCount, const TChar* rhsString, int rhsCount) noexcept;

	ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(const wchar_t* localeName, Compares comparesFlag, const wchar_t* lhsString,
																	   int lhsCount, const wchar_t* rhsString, int rhsCount) noexcept;

	ComparesStringReturn SYSTEM_DEFAULT_DECLARE	CompareStringOrdinalUseBinary(const wchar_t* lhsString, int lhsCount, const wchar_t* rhsString, int rhsCount, bool ignoreCase) noexcept;

	// srcCountºÍdestCount²»°üÀ¨¿ÕÖÕÖ¹·û
	int	SYSTEM_DEFAULT_DECLARE FoldStringUseMapping(LocaleIndependentMapping mapFlag, const TChar* src, int srcCount, TChar* dest, int destCount) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetStringTypeUseCharacterType(LanguageLocale locale, CharacterType infoType, const TChar* src, int srcCount, WindowWordPtr charType) noexcept;
}

#endif // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
