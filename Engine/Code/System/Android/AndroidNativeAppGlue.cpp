//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 23:33)

#include "System/SystemExport.h"

#include "Using/AndroidInputUsing.h"
#include "Using/AndroidNativeAppGlueUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Flags/WindowPictorialFlags.h"
#include "System/Window/Using/WindowRegistryUsing.h"

#ifdef SYSTEM_PLATFORM_ANDROID

void System::AppDummy() noexcept
{
    app_dummy();
}

System::WindowHWnd System::CreateVirtualWindow([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] const String& appName)
{
    return nullptr;
}

#elif defined(SYSTEM_PLATFORM_WIN32)

    #include "AndroidNativeAppGlue.h"
    #include "Flags/AndroidInputFlags.h"
    #include "Flags/AndroidNativeAppGlueFlags.h"
    #include "System/Helper/WindowsMacro.h"
    #include "System/Window/Flags/WindowClassStyleFlags.h"
    #include "System/Window/WindowCreate.h"
    #include "System/Window/WindowProcess.h"
    #include "System/Window/WindowRegister.h"

    #include <gsl/gsl_util>
   
void System::AppDummy() noexcept
{
}

namespace System
{
    AndroidApp* g_MainAndroidApp;
    WindowLResult SYSTEM_CALL_BACK AndroidProcess(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
    void InitWndClassEx(WindowClassEx& wndclassex, const String& appName) noexcept;
    WindowHWnd CreateSystemWindow(const String& appName);

    WindowLResult AppCmd(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
    WindowLResult KeyInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
    WindowLResult MotionInputEvent(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
    WindowLResult Destory(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept;
}

void System::InitWndClassEx(WindowClassEx& wndclassex, const String& appName) noexcept
{
    wndclassex.cbSize = sizeof(WindowClassEx);
    wndclassex.style = EnumCastUnderlying(WindowClassStyle::CommonUse);
    wndclassex.lpfnWndProc = AndroidProcess;
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

 
System::WindowHWnd System::CreateSystemWindow(const String& appName)  
{
    WindowRect rect{ 0, 0, 800, 600 };

    auto hwnd = CreateSystemWindow(appName.c_str(), SYSTEM_TEXT("WindowTitle"), WindowStyles::Default, EnumCastUnderlying(WindowPointUse::Default),
                                   EnumCastUnderlying(WindowPointUse::Default), rect, nullptr, nullptr, GetHInstance());

    if (g_MainAndroidApp->GetRunning() == nullptr)
    {
        g_MainAndroidApp->SetRunning(hwnd);
    }

    return hwnd;
}

System::WindowHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName)  
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

System::WindowLResult SYSTEM_CALL_BACK System::AndroidProcess(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
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

System::WindowLResult System::AppCmd(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam) noexcept
{
    g_MainAndroidApp->OnAppCmd(g_MainAndroidApp, message);

    return DefSystemWindowProc(hwnd, UnderlyingCastEnum<WindowMessages>(message), wParam, lParam);
}

System::WindowLResult System::KeyInputEvent([[maybe_unused]] WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
    AndroidInputEvent event{};

    event.SetAndroidInputEventType(AndroidInputEventType::Key);
    event.SetAndroidKeyEventAction(UnderlyingCastEnum<AndroidKeyEventAction>(message));
    event.SetAndroidKeyCodes(UnderlyingCastEnum<AndroidKeyCodes>(gsl::narrow_cast<int>(wParam)));

    g_MainAndroidApp->OnInputEvent(g_MainAndroidApp, &event);

    return 0;
}

System::WindowLResult System::MotionInputEvent([[maybe_unused]] WindowHWnd hwnd, WindowUInt message, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
    AndroidInputEvent event{};

    event.SetAndroidInputEventType(AndroidInputEventType::Motion);
    event.SetAndroidMotionEventAction(UnderlyingCastEnum<AndroidMotionEventAction>(message));

    g_MainAndroidApp->OnInputEvent(g_MainAndroidApp, &event);

    return 0;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
System::WindowLResult System::Destory(WindowHWnd hwnd, [[maybe_unused]] WindowUInt message, [[maybe_unused]] WindowWParam wParam, [[maybe_unused]] WindowLParam lParam) noexcept
{
    if (g_MainAndroidApp->GetRunning() == hwnd)
    {
        if (PostSystemQuitMessage())
        {
            g_MainAndroidApp->SetDestroyRequested(1);
        }       
    }

    return 0;
}
#include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

void System::AppDummy() noexcept
{
}

System::WindowHWnd System::CreateVirtualWindow([[maybe_unused]] AndroidApp* androidApp, [[maybe_unused]] const String& appName)
{
    return nullptr;
}
  
#endif  // SYSTEM_PLATFORM_ANDROID