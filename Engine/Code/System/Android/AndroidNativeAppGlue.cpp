// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:04)

#include "System/SystemExport.h"

#include "Using/AndroidInputUsing.h"
#include "Using/AndroidNativeAppGlueUsing.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Flags/WindowPictorialFlags.h"
#include "System/Window/Using/WindowRegistryUsing.h"

#ifdef SYSTEM_PLATFORM_ANDROID

void System
	::AppDummy() noexcept
{
	app_dummy();
}

System::WindowHWnd System
	::CreateVirtualWindow(AndroidApp* androidApp, const String& appName) noexcept
{
	SYSTEM_UNUSED_ARG(androidApp);
	SYSTEM_UNUSED_ARG(appName);

	return nullptr;
}

#elif defined(SYSTEM_PLATFORM_WIN32)

#include "AndroidNativeAppGlue.h" 
#include "Flags/AndroidInputFlags.h"
#include "Flags/AndroidNativeAppGlueFlags.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowCreate.h"
#include "System/Window/WindowProcess.h"
#include "System/Window/WindowRegister.h"
#include "System/Window/Flags/WindowClassStyleFlags.h"

#include <gsl/gsl_util>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
void System
	::AppDummy() noexcept
{

}

namespace System
{
	AndroidApp* g_MainAndroidApp;
	WindowLResult SYSTEM_CALL_BACK WindowProcess(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
	void InitWndClassEx(WindowClassEx& wndclassex, const String& appName) noexcept;
	WindowHWnd CreateSystemWindow(const String& appName) noexcept;

	WindowLResult AppCmd(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
	WindowLResult KeyInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
	WindowLResult MotionInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
	WindowLResult Destory(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept; 
}

void System
	::InitWndClassEx(WindowClassEx& wndclassex, const String& appName) noexcept
{
	wndclassex.cbSize = sizeof(WindowClassEx);
	wndclassex.style = EnumCastUnderlying(WindowClassStyle::CommonUse);
	wndclassex.lpfnWndProc = WindowProcess;
	wndclassex.cbClsExtra = 0;
	wndclassex.cbWndExtra = 0;
	wndclassex.hInstance = GetHInstance();
	wndclassex.hIcon = LoadSystemIcon(nullptr, g_Application);
	wndclassex.hCursor = LoadSystemCursor(nullptr, g_Arrow);
	wndclassex.hbrBackground = static_cast<WindowHBrush>(GetSystemStockObject(WindowBrushTypes::WhiteBrush));
	wndclassex.lpszMenuName = nullptr;
	wndclassex.lpszClassName = appName.c_str();
	wndclassex.hIconSm = wndclassex.hIcon;
}

namespace System
{
	WindowHWnd DoCreateSystemWindow(const String& appName)
	{
		WindowRect rect{ 0,0,800,600 };

		auto hwnd = CreateSystemWindow(appName.c_str(), SYSTEM_TEXT("WindowTitle"), WindowStyles::Default, EnumCastUnderlying(WindowPointUse::Default),
									   EnumCastUnderlying(WindowPointUse::Default), rect, nullptr, nullptr, GetHInstance());

		if (g_MainAndroidApp->running == nullptr)
		{
			g_MainAndroidApp->running = hwnd;
		}
		return hwnd;
	}
}

System::WindowHWnd System
	::CreateSystemWindow(const String& appName) noexcept
{	 
	return Disable26447<WindowHWnd>(DoCreateSystemWindow,appName, nullptr);
}

System::WindowHWnd System
	::CreateVirtualWindow(AndroidApp* androidApp, const String& appName) noexcept
{
	if (g_MainAndroidApp == nullptr)
	{
		g_MainAndroidApp = androidApp;
	}

	WindowClassEx wndclassex{ 0 };
	InitWndClassEx(wndclassex, appName);

	if (RegisterSystemClass(&wndclassex))
		return CreateSystemWindow(appName);
	else
		return nullptr;
}

System::WindowLResult SYSTEM_CALL_BACK System
	::WindowProcess(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
	switch (message)
	{
	case EnumCastUnderlying(AppCmd::InitWindow):
	case EnumCastUnderlying(AppCmd::TermWindow):
	case EnumCastUnderlying(AppCmd::WindowResized):
	{
		return AppCmd(hwnd, message, wParam, lParam);
	}

	case EnumCastUnderlying(AndroidKeyEventAction::Down):
	case EnumCastUnderlying(AndroidKeyEventAction::Up):
	{
		return KeyInputEvent(hwnd, message, wParam, lParam);  
	}

	case EnumCastUnderlying(AndroidMotionEventAction::Down):
	case EnumCastUnderlying(AndroidMotionEventAction::Up):
	case EnumCastUnderlying(AndroidMotionEventAction::Move):
	{
		return MotionInputEvent(hwnd, message, wParam, lParam);
	}

	case EnumCastUnderlying(AppCmd::Destory):
	{
		return Destory(hwnd, message, wParam, lParam);
	}

	default:
		return DefSystemWindowProc(hwnd, UnderlyingCastEnum<WindowMessages>(message), wParam, lParam);
	}
}

System::WindowLResult System
	::AppCmd(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
	g_MainAndroidApp->onAppCmd(g_MainAndroidApp, message);

	return DefSystemWindowProc(hwnd, UnderlyingCastEnum<WindowMessages>(message), wParam, lParam);
}

System::WindowLResult System
	::KeyInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
	AndroidInputEvent event{};

	event.m_AndroidInputEventType = AndroidInputEventType::Key;
	event.m_AndroidKeyEventAction = UnderlyingCastEnum<AndroidKeyEventAction>(message);
	event.m_AndroidKeyCodes = UnderlyingCastEnum<AndroidKeyCodes>(gsl::narrow_cast<uint32_t>(wParam));

	g_MainAndroidApp->onInputEvent(g_MainAndroidApp, &event);

	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;
}

System::WindowLResult System
	::MotionInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
	AndroidInputEvent event{};

	event.m_AndroidInputEventType = AndroidInputEventType::Motion;
	event.m_AndroidMotionEventAction = UnderlyingCastEnum<AndroidMotionEventAction>(message);

	g_MainAndroidApp->onInputEvent(g_MainAndroidApp, &event);

	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;
}

System::WindowLResult System
	::Destory(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
	if (g_MainAndroidApp->running == hwnd)
	{
		PostSystemQuitMessage();

		g_MainAndroidApp->SetDestroyRequested(1);
	}

	SYSTEM_UNUSED_ARG(message);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;
}

#else // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

void System
	::AppDummy() noexcept
{

}

System::WindowHWnd System
	::CreateVirtualWindow(AndroidApp* androidApp, const String& appName) noexcept
{
	SYSTEM_UNUSED_ARG(androidApp);
	SYSTEM_UNUSED_ARG(appName);

	return nullptr;
}
#include STSTEM_WARNING_POP 

#endif // SYSTEM_PLATFORM_ANDROID