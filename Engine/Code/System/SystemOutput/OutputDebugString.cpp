// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 23:52)

#include "System/SystemExport.h"

#include "OutputDebugString.h"
#include "System/Helper/Platform.h"
#include "System/Helper/UnusedMacro.h"

void System
	::OutputDebugStringWithChar(const char* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32    
	::OutputDebugStringA(outputString);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(outputString);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::OutputDebugStringWithWChar(const wchar_t* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::OutputDebugStringW(outputString);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(outputString);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::OutputDebugStringWithTChar(const TChar* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::OutputDebugString(outputString);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(outputString);
#endif // SYSTEM_PLATFORM_WIN32
}

