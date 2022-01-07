///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 23:24)

#include "System/SystemExport.h"

#include "Using/AndroidInputUsing.h"
#include "Using/AndroidNativeAppGlueUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"

#ifdef SYSTEM_PLATFORM_ANDROID

void System::AppDummy() noexcept
{
    app_dummy();
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp,
                                                const String& appName,
                                                AndroidApp::AppCmd appCmd,
                                                AndroidApp::InputEvent inputEvent)
{
    UnusedFunction(androidApp, appName, appCmd, inputEvent);

    return nullptr;
}

#elif defined(SYSTEM_PLATFORM_WIN32)

    #include "AndroidNativeAppGlue.h"
    #include "Flags/AndroidInputFlags.h"
    #include "Flags/AndroidNativeAppGlueFlags.h"
    #include "System/Helper/WindowsMacro.h"
    #include "System/Windows/Flags/WindowsClassStyleFlags.h"
    #include "System/Windows/WindowsCreate.h"
    #include "System/Windows/WindowsProcess.h"
    #include "System/Windows/WindowsRegister.h"

    #include <gsl/util>

void System::AppDummy() noexcept
{
}

namespace System
{
    AndroidApp* mainAndroidApp = nullptr;
    AndroidApp::AppCmd systemAppCmd = nullptr;
    AndroidApp::InputEvent systemInputEvent = nullptr;

    WindowsLResult SYSTEM_CALL_BACK AndroidProcess(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsClassEx GetWndClassEx(const String& appName) noexcept;
    NODISCARD WindowsHWnd CreateSystemWindow(const String& appName);

    NODISCARD WindowsLResult AppCmd(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult KeyInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult MotionInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult Destory(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
}

System::WindowsClassEx System::GetWndClassEx(const String& appName) noexcept
{
    WindowsClassEx wndclassex{ 0 };

    wndclassex.cbSize = sizeof(WindowsClassEx);
    wndclassex.style = EnumCastUnderlying(WindowsClassStyle::CommonUse);
    wndclassex.lpfnWndProc = AndroidProcess;
    wndclassex.cbClsExtra = 0;
    wndclassex.cbWndExtra = 0;
    wndclassex.hInstance = GetHInstance();
    wndclassex.hIcon = LoadSystemIcon(nullptr, g_Application);
    wndclassex.hCursor = LoadSystemCursor(nullptr, g_Arrow);
    wndclassex.hbrBackground = static_cast<WindowsHBrush>(GetSystemStockObject(WindowsBrushTypes::WhiteBrush));
    wndclassex.lpszMenuName = nullptr;
    wndclassex.lpszClassName = appName.c_str();
    wndclassex.hIconSm = wndclassex.hIcon;

    return wndclassex;
}

System::WindowsHWnd System::CreateSystemWindow(const String& appName)
{
    WindowsRect rect{ 0, 0, 800, 600 };

    auto hwnd = CreateSystemWindow(appName.c_str(),
                                   SYSTEM_TEXT("WindowTitle"),
                                   WindowsStyles::Default,
                                   EnumCastUnderlying(WindowsPointUse::Default),
                                   EnumCastUnderlying(WindowsPointUse::Default),
                                   rect,
                                   nullptr,
                                   nullptr,
                                   GetHInstance());

    if (mainAndroidApp->GetRunning() == nullptr)
    {
        mainAndroidApp->SetRunning(hwnd);
    }

    return hwnd;
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AndroidApp::AppCmd appCmd, AndroidApp::InputEvent inputEvent)
{
    if (mainAndroidApp == nullptr)
    {
        mainAndroidApp = androidApp;
    }

    auto wndclassex = GetWndClassEx(appName);

    if (RegisterSystemClass(&wndclassex))
    {
        if (inputEvent != nullptr)
        {
            systemInputEvent = inputEvent;
        }

        if (appCmd != nullptr)
        {
            systemAppCmd = appCmd;
        }

        return CreateSystemWindow(appName);
    }
    else
    {
        return nullptr;
    }
}

System::WindowsLResult SYSTEM_CALL_BACK System::AndroidProcess(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    switch (message)
    {
        case EnumCastUnderlying(AppCmdType::InitWindow):
            FALLTHROUGH;
        case EnumCastUnderlying(AppCmdType::TermWindow):
            FALLTHROUGH;
        case EnumCastUnderlying(AppCmdType::WindowResized):
        {
            return AppCmd(hwnd, message, wParam, lParam);
        }
        case EnumCastUnderlying(AndroidKeyEventAction::Down):
            FALLTHROUGH;
        case EnumCastUnderlying(AndroidKeyEventAction::Up):
        {
            return KeyInputEvent(hwnd, message, wParam, lParam);
        }
        case EnumCastUnderlying(AndroidMotionEventAction::Down):
            FALLTHROUGH;
        case EnumCastUnderlying(AndroidMotionEventAction::Up):
            FALLTHROUGH;
        case EnumCastUnderlying(AndroidMotionEventAction::Move):
        {
            return MotionInputEvent(hwnd, message, wParam, lParam);
        }
        case EnumCastUnderlying(AppCmdType::Destory):
        {
            return Destory(hwnd, message, wParam, lParam);
        }
        default:
        {
            return DefSystemWindowProc(hwnd, UnderlyingCastEnum<WindowsMessages>(message), wParam, lParam);
        }
    }
}

System::WindowsLResult System::AppCmd(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    systemAppCmd(mainAndroidApp, message);

    return DefSystemWindowProc(hwnd, UnderlyingCastEnum<WindowsMessages>(message), wParam, lParam);
}

System::WindowsLResult System::KeyInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent event{};

    event.SetAndroidInputEventType(AndroidInputEventType::Key);
    event.SetAndroidKeyEventAction(UnderlyingCastEnum<AndroidKeyEventAction>(message));
    event.SetAndroidKeyCodes(UnderlyingCastEnum<AndroidKeyCodes>(gsl::narrow_cast<int>(wParam)));

    systemInputEvent(mainAndroidApp, &event);

    UnusedFunction(hwnd, lParam);

    return 0;
}

System::WindowsLResult System::MotionInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent event{};

    event.SetAndroidInputEventType(AndroidInputEventType::Motion);
    event.SetAndroidMotionEventAction(UnderlyingCastEnum<AndroidMotionEventAction>(message));

    systemInputEvent(mainAndroidApp, &event);

    UnusedFunction(hwnd, wParam, lParam);

    return 0;
}

System::WindowsLResult System::Destory(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    if (mainAndroidApp->GetRunning() == hwnd)
    {
        if (PostSystemQuitMessage() == 0)
        {
            mainAndroidApp->SetDestroyRequested(1);
        }
    }

    UnusedFunction(hwnd, message, wParam, lParam);

    return 0;
}

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

void System::AppDummy() noexcept
{
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AndroidApp::AppCmd appCmd, AndroidApp::InputEvent inputEvent)
{
    UnusedFunction(androidApp, appName, appCmd, inputEvent);

    return nullptr;
}

#endif  // SYSTEM_PLATFORM_ANDROID