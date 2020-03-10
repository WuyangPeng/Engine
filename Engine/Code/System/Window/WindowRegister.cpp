// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:39)

#include "System/SystemExport.h"

#include "WindowRegister.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::WindowHGdiObj System
	::GetSystemStockObject(WindowBrushTypes background) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetStockObject(EnumCastUnderlying(background));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(background);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHCursor System
	::LoadSystemCursor(WindowHInstance instance, const TChar* cursor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LoadCursor(instance, cursor);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(instance);
	SYSTEM_UNUSED_ARG(cursor);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHIcon System
	::LoadSystemIcon(WindowHInstance instance, const TChar* icon) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LoadIcon(instance, icon);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(instance);
	SYSTEM_UNUSED_ARG(icon);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowAtom System
	::RegisterSystemClass(const WindowClassEx* wndClassEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::RegisterClassEx(wndClassEx);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(wndClassEx);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System
	::RegisterSystemWindowMessage(const TChar* string) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::RegisterWindowMessage(string);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(string);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}
