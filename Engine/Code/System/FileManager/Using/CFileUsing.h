// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:53)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_USING_H
#define SYSTEM_FILE_MANAGE_C_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h" 

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_LINUX	
	using OffType = off_t;
#else // !SYSTEM_PLATFORM_LINUX		
	using OffType = _off_t;
#endif // SYSTEM_PLATFORM_LINUX

	using PosType = fpos_t;
	constexpr auto g_CFileError = EOF;

#if defined(TCRE_USE_GCC)
	using CFileString = std::string;
	#define SYSTEM_FILE_TEXT(quote) quote
#else // !TCRE_USE_GCC
	using CFileString = String;
	#define SYSTEM_FILE_TEXT(quote) SYSTEM_TEXT(quote)
#endif // TCRE_USE_GCC
}

#endif // SYSTEM_FILE_MANAGE_C_FILE_USING_H