// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:38)

#include "System/SystemExport.h"

#include "ConsoleScreenBuffer.h"
#include "Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::WindowHandle System
	::CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess, ConsoleScreenBufferShareMode shareMode, const WindowSecurityAttributes* securityAttributes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateConsoleScreenBuffer(EnumCastUnderlying(desiredAccess), EnumCastUnderlying(shareMode), securityAttributes, EnumCastUnderlying(ConsoleScreenBuffer::TextModeBuffer), nullptr);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(shareMode);
	SYSTEM_UNUSED_ARG(securityAttributes);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseSystemConsole(WindowHandle consoleHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(consoleHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept
{
	securityAttributes.nLength = sizeof(WindowSecurityAttributes);
	securityAttributes.lpSecurityDescriptor = nullptr;
	securityAttributes.bInheritHandle = BoolConversion(inheritHandle);
}

bool System
	::GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleScreenBufferInfo(consoleOutput, consoleScreenBufferInfo) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(consoleScreenBufferInfo);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemConsoleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(consoleScreenBufferInfoEx);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetConsoleHandleScreenBufferInfo(WindowHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(consoleScreenBufferInfoEx);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemConsoleScreenBufferSize(WindowHandle consoleOutput, ConsoleCoord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetConsoleScreenBufferSize(consoleOutput, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ScrollSystemConsoleScreenBuffer(WindowHandle consoleOutput, const ConsoleSmallRect* scrollRectangle, const ConsoleSmallRect* clipRectangle,
									  ConsoleCoord destinationOrigin, const ConsoleCharInfo* fill) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ScrollConsoleScreenBuffer(consoleOutput, scrollRectangle, clipRectangle, destinationOrigin, fill) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(consoleOutput);
	SYSTEM_UNUSED_ARG(scrollRectangle);
	SYSTEM_UNUSED_ARG(clipRectangle);
	SYSTEM_UNUSED_ARG(destinationOrigin);
	SYSTEM_UNUSED_ARG(fill);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
