///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/26 15:35)

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

    WindowsLResult SYSTEM_CALL_BACK AndroidProcess(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsClassEx GetWindowClass(const String& appName) noexcept;
    MAYBE_NULLPTR WindowsHWnd CreateSystemWindow(const String& appName);

    NODISCARD WindowsLResult AppCommandEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult KeyInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult MotionInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
    NODISCARD WindowsLResult Destroy(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;
}

System::WindowsClassEx System::GetWindowClass(const String& appName) noexcept
{
    WindowsClassEx windowsClassEx{};

    windowsClassEx.cbSize = sizeof(WindowsClassEx);
    windowsClassEx.style = EnumCastUnderlying(WindowsClassStyle::CommonUse);
    windowsClassEx.lpfnWndProc = AndroidProcess;
    windowsClassEx.cbClsExtra = 0;
    windowsClassEx.cbWndExtra = 0;
    windowsClassEx.hInstance = GetHInstance();
    windowsClassEx.hIcon = LoadSystemIcon(nullptr, gApplication);
    windowsClassEx.hCursor = LoadSystemCursor(nullptr, gArrow);
    windowsClassEx.hbrBackground = static_cast<WindowsHBrush>(GetSystemStockObject(WindowsBrushTypes::WhiteBrush));
    windowsClassEx.lpszMenuName = nullptr;
    windowsClassEx.lpszClassName = appName.c_str();
    windowsClassEx.hIconSm = windowsClassEx.hIcon;

    return windowsClassEx;
}

System::WindowsHWnd System::CreateSystemWindow(const String& appName)
{
    constexpr WindowsRect rect{ 0, 0, 800, 600 };

    const auto hWnd = CreateSystemWindow(appName,
                                         SYSTEM_TEXT("Android Virtual Window"),
                                         WindowsStyles::Default,
                                         EnumCastUnderlying(WindowsPointUse::Default),
                                         EnumCastUnderlying(WindowsPointUse::Default),
                                         rect,
                                         nullptr,
                                         nullptr,
                                         GetHInstance());

    if (hWnd != nullptr && mainAndroidApp->GetRunning() == nullptr)
    {
        mainAndroidApp->SetRunning(hWnd);
    }

    return hWnd;
}

System::WindowsHWnd System::CreateVirtualWindow(AndroidApp* androidApp, const String& appName, AppCommand appCommand, InputEvent inputEvent)
{
    if (mainAndroidApp == nullptr)
    {
        mainAndroidApp = androidApp;
    }

    const auto windowsClassEx = GetWindowClass(appName);

    if (RegisterSystemClass(&windowsClassEx))
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

System::WindowsLResult SYSTEM_CALL_BACK System::AndroidProcess(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    switch (message)
    {
        case EnumCastUnderlying(AppCommandType::InitWindow):
        case EnumCastUnderlying(AppCommandType::TermWindow):
        case EnumCastUnderlying(AppCommandType::WindowResized):
        {
            return AppCommandEvent(hWnd, message, wParam, lParam);
        }

        case EnumCastUnderlying(AndroidKeyEventAction::Down):
        case EnumCastUnderlying(AndroidKeyEventAction::Up):
        {
            return KeyInputEvent(hWnd, message, wParam, lParam);
        }

        case EnumCastUnderlying(AndroidMotionEventAction::Down):
        case EnumCastUnderlying(AndroidMotionEventAction::Up):
        case EnumCastUnderlying(AndroidMotionEventAction::Move):
        {
            return MotionInputEvent(hWnd, message, wParam, lParam);
        }

        case EnumCastUnderlying(AppCommandType::Destroy):
        {
            return Destroy(hWnd, message, wParam, lParam);
        }

        default:
        {
            return DefaultSystemWindowProcess(hWnd, static_cast<WindowsMessages>(message), wParam, lParam);
        }
    }
}

System::WindowsLResult System::AppCommandEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    systemAppCommand(mainAndroidApp, gsl::narrow_cast<int32_t>(message));

    return DefaultSystemWindowProcess(hWnd, static_cast<WindowsMessages>(message), wParam, lParam);
}

System::WindowsLResult System::KeyInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Key,
                                         static_cast<AndroidKeyEventAction>(message),
                                         UnderlyingCastEnum<AndroidKeyCodes>(gsl::narrow_cast<int>(wParam)) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hWnd, lParam);

    return 0;
}

System::WindowsLResult System::MotionInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Motion, static_cast<AndroidMotionEventAction>(message) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hWnd, wParam, lParam);

    return 0;
}

System::WindowsLResult System::Destroy(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
{
    if (mainAndroidApp->GetRunning() == hWnd && PostSystemQuitMessage() == 0)
    {
        mainAndroidApp->SetDestroyRequested(1);
    }

    UnusedFunction(hWnd, message, wParam, lParam);

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