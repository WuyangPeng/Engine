// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/09 21:37)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

System::WindowHandle System
	::GetStandardHandle(StandardHandle standardhandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetStdHandle(EnumCastUnderlying(standardhandle));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(standardhandle);

	return g_InvalidHandleValue;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsHandleValid(WindowHandle handle) noexcept
{
	if (handle != g_InvalidHandleValue && handle != nullptr)
		return true;
	else
		return false;
}

bool System
	::SetStandardHandle(StandardHandle standardhandle, WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetStdHandle(EnumCastUnderlying(standardhandle), handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(standardhandle);
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetStandardHandle(StandardHandle standardhandle, WindowHandle handle, WindowHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetStdHandleEx(EnumCastUnderlying(standardhandle), handle, previousHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(standardhandle);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(previousHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

