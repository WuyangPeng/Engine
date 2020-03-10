// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:22)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H

#include "System/Helper/Platform.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using CodePageInfo = CPINFO;
	using CodePageInfoPtr = LPCPINFO;
	using CodePageInfoEx = CPINFOEX;
	using CodePageInfoExPtr = LPCPINFOEX;

#else // !SYSTEM_PLATFORM_WIN32

	static constexpr auto g_MaxDefaultChar = 2;
	static constexpr auto g_MaxLeadBytes = 12;

	struct CodePageInfo
	{
		uint32_t MaxCharSize;
		uint8_t DefaultChar[g_MaxDefaultChar];
		uint8_t LeadByte[g_MaxLeadBytes];
	};
	using CodePageInfoPtr = CodePageInfo*;

	struct CodePageInfoEx
	{
		uint32_t MaxCharSize;
		uint8_t DefaultChar[g_MaxDefaultChar];
		uint8_t LeadByte[g_MaxLeadBytes];
		TChar UnicodeDefaultChar;
		uint32_t CodePage;
		TChar CodePageName[g_MaxPath];
	};
	using CodePageInfoExPtr = CodePageInfoEx*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H
