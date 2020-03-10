// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:22)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H

#include "System/Helper/Platform.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	static const wchar_t* g_LocaleUserDefault{ LOCALE_NAME_USER_DEFAULT };
	static const wchar_t* g_LocaleNameInvariant{ LOCALE_NAME_INVARIANT };
	static const wchar_t* g_LocaleSystemDefault{ LOCALE_NAME_SYSTEM_DEFAULT };	 

#else // !SYSTEM_PLATFORM_WIN32
	 
	static const wchar_t* g_LocaleUserDefault{ nullptr };
	static const wchar_t* g_LocaleNameInvariant{ L"" };
	static const wchar_t* g_LocaleSystemDefault{ L"!x-sys-default-locale" };

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
