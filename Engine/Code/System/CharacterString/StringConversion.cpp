// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:28)

#include "System/SystemExport.h"

#include "StringConversion.h"
#include "CodePage.h"
#include "Flags/CodePageFlags.h"
#include "Flags/StringConversionFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

#ifndef SYSTEM_PLATFORM_WIN32  
	#ifdef SYSTEM_PLATFORM_ANDROID
		#include <iconv.h>
	#else // !SYSTEM_PLATFORM_ANDROID
		#include <locale>
		#include <cstdlib>
	#endif // SYSTEM_PLATFORM_ANDROID
#endif // SYSTEM_PLATFORM_WIN32

#ifndef SYSTEM_PLATFORM_WIN32

namespace System
{
	const char* SYSTEM_HIDDEN_DECLARE GetLocale(CodePage codePage) noexcept
	{
		if (codePage == CodePage::UTF8)
			return "zh_CN.utf8";
		else
			return "chs";
	}

	int SYSTEM_HIDDEN_DECLARE IncreaseNullNumber(int readSize) noexcept
	{
		// ¥ÌŒÛÕ≥“ª∑µªÿ0
		if (readSize < 0)
			return 0;
		else
			return readSize + 1;
	}

	int SYSTEM_HIDDEN_DECLARE MultiByteToWideCharUseMbstowcs(CodePage codePage, const char* multiByte, wchar_t* wideChar, int wideCharLength) noexcept
	{
		auto currentLocale = setlocale(LC_ALL, nullptr);

		setlocale(LC_ALL, GetLocale(codePage));

		auto readSize = static_cast<int>(::mbstowcs(wideChar, multiByte, wideCharLength));

		setlocale(LC_ALL, currentLocale);

		// ∑µªÿ÷µ∞¸¿®ø’÷’÷π∑˚	 
		return IncreaseNullNumber(readSize);
	}
}

#endif // SYSTEM_PLATFORM_WIN32

int System
	::MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
	// ¥˙¬Î“≥
	const auto codePage = GetANSICodePage();
	constexpr auto defaultMultiByte = MultiByte::NoFlags;

	return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System
	::UTF8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
	const auto codePage = CodePage::UTF8;
	constexpr auto defaultMultiByte = MultiByte::NoFlags;

	return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System
	::MultiByteConversionWideChar(CodePage codePage, MultiByte flag, const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32    
	return ::MultiByteToWideChar(EnumCastUnderlying(codePage), EnumCastUnderlying(flag), multiByte, multiByteLength, wideChar, wideCharLength);

#else // !SYSTEM_PLATFORM_WIN32     
	SYSTEM_UNUSED_ARG(flag);

	// ∑µªÿ÷µ∞¸¿®ø’÷’÷π∑˚
	if (wideChar != nullptr)
		return MultiByteToWideCharUseMbstowcs(codePage, multiByte, wideChar, wideCharLength);
	else
		return multiByteLength;
#endif // SYSTEM_PLATFORM_WIN32		 
}

#ifndef SYSTEM_PLATFORM_WIN32
namespace System
{
	int SYSTEM_HIDDEN_DECLARE WideCharToMultiByteUseWcstombs(CodePage codePage, const wchar_t* wideChar, char* multiByte, int multiByteLength) noexcept
	{
		auto currentLocale = setlocale(LC_ALL, nullptr);

		setlocale(LC_ALL, GetLocale(codePage));

		auto readSize = static_cast<int>(::wcstombs(multiByte, wideChar, multiByteLength));

		setlocale(LC_ALL, currentLocale);

		// ∑µªÿ÷µ∞¸¿®ø’÷’÷π∑˚
		return IncreaseNullNumber(readSize);
	}
}
#endif // SYSTEM_PLATFORM_WIN32

int System
	::WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
	// ¥˙¬Î“≥
	const auto codePage = GetANSICodePage();
	constexpr WideChar defaultWideChar = WideChar::NoFlags;

	return WideCharConversionMultiByte(codePage, defaultWideChar, wideChar, wideCharLength, multiByte, multiByteLength, nullptr, nullptr);
}

int System
	::WideCharConversionUTF8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
	const auto codePage = CodePage::UTF8;
	constexpr WideChar defaultWideChar = WideChar::NoFlags;

	return WideCharConversionMultiByte(codePage, defaultWideChar, wideChar, wideCharLength, multiByte, multiByteLength, nullptr, nullptr);
}

int System
	::WideCharConversionMultiByte(CodePage codePage, WideChar flag, const wchar_t* wideChar, int wideCharLength,
								  char* multiByte, int multiByteLength, const char* defaultChar, bool* usedDefaultChar) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };

	const auto size = ::WideCharToMultiByte(EnumCastUnderlying(codePage), EnumCastUnderlying(flag), wideChar, wideCharLength, multiByte, multiByteLength, defaultChar, &result);
	BoolConversion(result, usedDefaultChar);

	return size;
#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(flag);
	SYSTEM_UNUSED_ARG(defaultChar);
	SYSTEM_UNUSED_ARG(usedDefaultChar);

	// ∑µªÿ÷µ∞¸¿®ø’÷’÷π∑˚
	if (multiByte != nullptr)
		return WideCharToMultiByteUseWcstombs(codePage, wideChar, multiByte, multiByteLength);
	else
		return wideCharLength * 2;

#endif // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System
	::CompareStringUseLocale(LanguageLocale locale, Compares comparesFlag, const TChar* lhsString, int lhsCount, const TChar* rhsString, int rhsCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	return UnderlyingCastEnum<ComparesStringReturn>(::CompareString(EnumCastUnderlying(locale), EnumCastUnderlying(comparesFlag), lhsString, lhsCount, rhsString, rhsCount));

#else // !SYSTEM_PLATFORM_WIN32 
	SYSTEM_UNUSED_ARG(locale);
	SYSTEM_UNUSED_ARG(comparesFlag);
	SYSTEM_UNUSED_ARG(lhsCount);
	SYSTEM_UNUSED_ARG(rhsCount);

	if (lhsString < rhsString)
		return ComparesStringReturn::LessThan;
	else if (rhsString < lhsString)
		return ComparesStringReturn::GreaterThan;
	else
		return ComparesStringReturn::Equal;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::ComparesStringReturn System
	::CompareStringUseLocale(const wchar_t* localeName, Compares comparesFlag, const wchar_t* lhsString, int lhsCount, const wchar_t* rhsString, int rhsCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringEx(localeName, EnumCastUnderlying(comparesFlag), lhsString, lhsCount, rhsString, rhsCount, nullptr, nullptr, 0));

#else // !SYSTEM_PLATFORM_WIN32 
	SYSTEM_UNUSED_ARG(localeName);
	SYSTEM_UNUSED_ARG(comparesFlag);
	SYSTEM_UNUSED_ARG(lhsCount);
	SYSTEM_UNUSED_ARG(rhsCount);

	if (lhsString < rhsString)
		return ComparesStringReturn::LessThan;
	else if (rhsString < lhsString)
		return ComparesStringReturn::GreaterThan;
	else
		return ComparesStringReturn::Equal;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::ComparesStringReturn System
	::CompareStringOrdinalUseBinary(const wchar_t* lhsString, int lhsCount, const wchar_t* rhsString, int rhsCount, bool ignoreCase) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringOrdinal(lhsString, lhsCount, rhsString, rhsCount, BoolConversion(ignoreCase)));

#else // !SYSTEM_PLATFORM_WIN32 
	SYSTEM_UNUSED_ARG(ignoreCase);
	SYSTEM_UNUSED_ARG(lhsCount);
	SYSTEM_UNUSED_ARG(rhsCount);

	if (lhsString < rhsString)
		return ComparesStringReturn::LessThan;
	else if (rhsString < lhsString)
		return ComparesStringReturn::GreaterThan;
	else
		return ComparesStringReturn::Equal;
#endif // SYSTEM_PLATFORM_WIN32	
}

int	System
	::FoldStringUseMapping(LocaleIndependentMapping mapFlag, const TChar* src, int srcCount, TChar* dest, int destCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FoldString(EnumCastUnderlying(mapFlag), src, srcCount, dest, destCount);
#else // !SYSTEM_PLATFORM_WIN32 
	SYSTEM_UNUSED_ARG(mapFlag);
	SYSTEM_UNUSED_ARG(src);
	SYSTEM_UNUSED_ARG(srcCount);
	SYSTEM_UNUSED_ARG(dest);
	SYSTEM_UNUSED_ARG(destCount);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::GetStringTypeUseCharacterType(LanguageLocale locale, CharacterType infoType, const TChar* src, int srcCount, WindowWordPtr charType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (g_False != ::GetStringTypeEx(EnumCastUnderlying(locale), EnumCastUnderlying(infoType), src, srcCount, charType))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(locale);
	SYSTEM_UNUSED_ARG(infoType);
	SYSTEM_UNUSED_ARG(src);
	SYSTEM_UNUSED_ARG(srcCount);
	SYSTEM_UNUSED_ARG(charType);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

