// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:40)

#include "System/SystemExport.h"

#include "WindowUser.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::PostSystemThreadMessage(WindowDWord threadID, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::PostThreadMessage(threadID, EnumCastUnderlying(msg), wParam, lParam) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadID);
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemInvalidateRect(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InvalidateRect(hwnd, nullptr, g_True) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hWnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UpdateSystemWindows(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::UpdateWindow(hwnd) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hWnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
