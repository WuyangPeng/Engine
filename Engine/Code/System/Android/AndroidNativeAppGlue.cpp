///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/12 9:37)

#include "System/SystemExport.h"

#include "AndroidNativeAppGlue.h"
#include "System/Helper/Tools.h"

#if defined(SYSTEM_PLATFORM_WIN32)

    #include "Flags/AndroidInputFlags.h"
    #include "Flags/AndroidNativeAppGlueFlags.h"
    #include "System/Windows/Flags/WindowsClassStyleFlags.h"
    #include "System/Windows/Flags/WindowsFlags.h"
    #include "System/Windows/Flags/WindowsPictorialFlags.h"
    #include "System/Windows/Using/WindowsRegistryUsing.h"
    #include "System/Windows/WindowsCreate.h"
    #include "System/Windows/WindowsProcess.h"
    #include "System/Windows/WindowsRegister.h"

    #include <gsl/util>

#endif  // SYSTEM_PLATFORM_WIN32

#ifdef SYSTEM_PLATFORM_ANDROID

void System::AppDummy() noexcept
{
    app_dummy();
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp,
                                                const String& appName,
                                                AppCommand appCommand,
                                                InputEvent inputEvent)
{
    UnusedFunction(androidApp, appName, appCommand, inputEvent);

    return nullptr;
}

#elif defined(SYSTEM_PLATFORM_WIN32)

void System::AppDummy() noexcept
{
}

namespace System
{
    AndroidApp* mainAndroidApp = nullptr;
    AppCommand systemAppCommand = nullptr;
    InputEvent systemInputEvent = nullptr;

    WindowsLResult SYSTEM_CALL_BACK AndroidProcess(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsClassEx GetWindowClass(const String& appName) noexcept;
    MAYBE_NULLPTR WindowsHWnd CreateSystemWindow(const String& appName);

    NODISCARD WindowsLResult AppCommandEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult KeyInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult MotionInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult Destory(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
}

System::WindowsClassEx System::GetWindowClass(const String& appName) noexcept
{
    WindowsClassEx wndclassex{};

    wndclassex.cbSize = sizeof(WindowsClassEx);
    wndclassex.style = EnumCastUnderlying(WindowsClassStyle::CommonUse);
    wndclassex.lpfnWndProc = AndroidProcess;
    wndclassex.cbClsExtra = 0;
    wndclassex.cbWndExtra = 0;
    wndclassex.hInstance = GetHInstance();
    wndclassex.hIcon = LoadSystemIcon(nullptr, gApplication);
    wndclassex.hCursor = LoadSystemCursor(nullptr, gArrow);
    wndclassex.hbrBackground = static_cast<WindowsHBrush>(GetSystemStockObject(WindowsBrushTypes::WhiteBrush));
    wndclassex.lpszMenuName = nullptr;
    wndclassex.lpszClassName = appName.c_str();
    wndclassex.hIconSm = wndclassex.hIcon;

    return wndclassex;
}

System::WindowsHWnd System::CreateSystemWindow(const String& appName)
{
    constexpr WindowsRect rect{ 0, 0, 800, 600 };

    auto hwnd = CreateSystemWindow(appName.c_str(),
                                   SYSTEM_TEXT("Android Virtual Window"),
                                   WindowsStyles::Default,
                                   EnumCastUnderlying(WindowsPointUse::Default),
                                   EnumCastUnderlying(WindowsPointUse::Default),
                                   rect,
                                   nullptr,
                                   nullptr,
                                   GetHInstance());

    if (hwnd != nullptr && mainAndroidApp->GetRunning() == nullptr)
    {
        mainAndroidApp->SetRunning(hwnd);
    }

    return hwnd;
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AppCommand appCommand, InputEvent inputEvent)
{
    if (mainAndroidApp == nullptr)
    {
        mainAndroidApp = androidApp;
    }

    auto wndclassex = GetWindowClass(appName);

    if (RegisterSystemClass(&wndclassex))
    {
        if (inputEvent != nullptr)
        {
            systemInputEvent = inputEvent;
        }

        if (appCommand != nullptr)
        {
            systemAppCommand = appCommand;
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
        case EnumCastUnderlying(AppCommandType::InitWindow):
            FALLTHROUGH;
        case EnumCastUnderlying(AppCommandType::TermWindow):
            FALLTHROUGH;
        case EnumCastUnderlying(AppCommandType::WindowResized):
        {
            return AppCommandEvent(hwnd, message, wParam, lParam);
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
        case EnumCastUnderlying(AppCommandType::Destory):
        {
            return Destory(hwnd, message, wParam, lParam);
        }
        default:
        {
            return DefaultSystemWindowProcess(hwnd, UnderlyingCastEnum<WindowsMessages>(message), wParam, lParam);
        }
    }
}

System::WindowsLResult System::AppCommandEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    systemAppCommand(mainAndroidApp, message);

    return DefaultSystemWindowProcess(hwnd, UnderlyingCastEnum<WindowsMessages>(message), wParam, lParam);
}

System::WindowsLResult System::KeyInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Key,
                                         UnderlyingCastEnum<AndroidKeyEventAction>(message),
                                         UnderlyingCastEnum<AndroidKeyCodes>(gsl::narrow_cast<int>(wParam)) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hwnd, lParam);

    return 0;
}

System::WindowsLResult System::MotionInputEvent(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Motion, UnderlyingCastEnum<AndroidMotionEventAction>(message) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hwnd, wParam, lParam);

    return 0;
}

System::WindowsLResult System::Destory(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    if (mainAndroidApp->GetRunning() == hwnd && PostSystemQuitMessage() == 0)
    {
        mainAndroidApp->SetDestroyRequested(1);
    }

    UnusedFunction(hwnd, message, wParam, lParam);

    return 0;
}

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

void System::AppDummy() noexcept
{
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AppCommand appCommand, InputEvent inputEvent)
{
    UnusedFunction(androidApp, appName, appCommand, inputEvent);

    return nullptr;
}

#endif  // SYSTEM_PLATFORM_ANDROID