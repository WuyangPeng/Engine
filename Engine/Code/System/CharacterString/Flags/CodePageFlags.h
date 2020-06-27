// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 15:37)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class CodePage
	{
		ACP = CP_ACP,
		OEMCP = CP_OEMCP,
		MACCP = CP_MACCP,
		ThreadACP = CP_THREAD_ACP,
		Symbol = CP_SYMBOL,
		UTF7 = CP_UTF7,
		UTF8 = CP_UTF8,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class CodePage
	{
		ACP = 0,
		OEMCP = 1,
		MACCP = 2,
		ThreadACP = 3,
		Symbol = 42,
		UTF7 = 65000,
		UTF8 = 65001,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
