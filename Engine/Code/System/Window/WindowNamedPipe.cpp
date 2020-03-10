// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:39)

#include "System/SystemExport.h"

#include "WindowNamedPipe.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::CreateSystemPipe(WindowHandlePtr readPipe, WindowHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreatePipe(readPipe, writePipe, pipeAttributes, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(readPipe);
	SYSTEM_UNUSED_ARG(writePipe);
	SYSTEM_UNUSED_ARG(pipeAttributes);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseSystemPipe(WindowHandle pipeHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(pipeHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pipeHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
