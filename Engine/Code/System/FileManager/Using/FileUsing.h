// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:53)

#ifndef SYSTEM_FILE_MANAGE_FILE_USING_H
#define SYSTEM_FILE_MANAGE_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	  

	constexpr WindowDWord g_InvalidFileSize{ INVALID_FILE_SIZE };
	constexpr WindowDWord g_InvalidSetFilePointer{ INVALID_SET_FILE_POINTER };

	using FileTime = FILETIME;
	using FileTimePtr = LPFILETIME;

#else // !SYSTEM_PLATFORM_WIN32	

	constexpr WindowDWord g_InvalidFileSize{ 0xFFFFFFFF };
	constexpr WindowDWord g_InvalidSetFilePointer{ static_cast<WindowDWord>(-1) };

	struct FileTime
	{
		uint32_t dwLowDateTime;
		uint32_t dwHighDateTime;
	};

	using FileTimePtr = FileTime*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_FILE_MANAGE_FILE_USING_H