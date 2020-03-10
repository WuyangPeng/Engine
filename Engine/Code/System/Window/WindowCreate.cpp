// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:38)

#include "System/SystemExport.h"

#include "WindowCreate.h"
#include "Flags/WindowCreateFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

#include <array>

using std::array;

bool System
	::AdjustSystemWindowRect(WindowRect* rect, WindowStyles styles) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AdjustWindowRect(rect, EnumCastUnderlying(styles), g_False) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(ret);
	SYSTEM_UNUSED_ARG(styles);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}


System::WindowHWnd System
	::CreateSystemWindow(const String& className, const String& windowsName, WindowStyles styles, int x, int y,
						 WindowRect rect, WindowHWnd parent, WindowHMenu menu, WindowHInstance instance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateWindow(className.c_str(), windowsName.c_str(), EnumCastUnderlying(styles), x, y, rect.right - rect.left + 1, rect.bottom - rect.top + 1, parent, menu, instance, nullptr);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(className);
	SYSTEM_UNUSED_ARG(windowsName);
	SYSTEM_UNUSED_ARG(styles);
	SYSTEM_UNUSED_ARG(x);
	SYSTEM_UNUSED_ARG(y);
	SYSTEM_UNUSED_ARG(rect);
	SYSTEM_UNUSED_ARG(parent);
	SYSTEM_UNUSED_ARG(menu);
	SYSTEM_UNUSED_ARG(instance);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemClassName(WindowHWnd hwnd, String& className)
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr auto maxCount = 256;
	array<TChar, maxCount> name{};

	if (::GetClassName(hwnd, name.data(), maxCount) == 0)
	{
		className.clear();
		return false;
	}
	else
	{
		className = name.data();
		return true;
	}
#else // !SYSTEM_PLATFORM_WIN32
	className.clear();

	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
	}


bool System
	::GetWindowTextString(WindowHWnd hwnd, String& windowText)
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr int maxCount{ 256 };
	array<TChar, maxCount> name{};

	if (::GetWindowText(hwnd, name.data(), maxCount) == 0)
	{
		windowText.clear();
		return false;
	}
	else
	{
		windowText = name.data();
		return true;
	}
#else // !SYSTEM_PLATFORM_WIN32
	windowText.clear();

	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHInstance System
	::GetHInstance() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetModuleHandle(nullptr);
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RemoveMenuCloseButton(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	auto hmenu = GetWindowSystemMenu(hwnd);
	if (hmenu != nullptr && RemoveSystemMenu(hmenu, SystemMenuCommand::Close, MenuItem::ByCommand))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHMenu System
	::GetWindowSystemMenu(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSystemMenu(hwnd, g_False);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RemoveSystemMenu(WindowHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RemoveMenu(menu, EnumCastUnderlying(position), EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(menu);
	SYSTEM_UNUSED_ARG(position);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
