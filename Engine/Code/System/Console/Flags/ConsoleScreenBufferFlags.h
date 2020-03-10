// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:31)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H

#include "System/Helper/Platform.h"
#include "System/Helper/EnumMacro.h"

namespace System
{ 
#ifdef SYSTEM_PLATFORM_WIN32

	enum class DesiredAccessGeneric : uint32_t
	{
		Read = GENERIC_READ,
		Write = GENERIC_WRITE,
		Execute = GENERIC_EXECUTE,
		All = GENERIC_ALL,
		ReadAndWrite = Read | Write,			
	};	
	  
	enum class ConsoleScreenBufferShareMode 
	{
		Read = FILE_SHARE_READ,
		Write = FILE_SHARE_WRITE,
		Delete = FILE_SHARE_DELETE,
		ReadAndWrite = Read | Write,		
	};	

	enum class ConsoleScreenBuffer
	{
		TextModeBuffer = CONSOLE_TEXTMODE_BUFFER,					
	};	
	
#else // !SYSTEM_PLATFORM_WIN32

	enum class DesiredAccessGeneric 
	{
		Read =  0x80000000L,
		Write = 0x40000000L,
		Execute = 0x20000000L,
		All = 0x10000000L,
		ReadAndWrite = Read | Write,	
	};	

	enum class ConsoleScreenBufferShareMode 
	{
		Read = 0x00000001,
		Write = 0x00000002,
		Delete = 0x00000004,
		ReadAndWrite = Read | Write,		
	};	

	enum class ConsoleScreenBuffer
	{
		TextModeBuffer = 1,					
	};
	
#endif // SYSTEM_PLATFORM_WIN32 

	ENUM_ORABLE_OPERATOR_DEFINE(DesiredAccessGeneric);
}

#endif // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H
