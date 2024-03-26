/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:20)

#include "System/SystemExport.h"

#include "AndroidNativeAppGlue.h"
#include "System/Helper/Tools.h"

#if defined(SYSTEM_PLATFORM_WIN32)

    #include "Flags/AndroidInputFlags.h"
    #include "Flags/AndroidNativeAppGlueFlags.h"
    #include "System/Helper/PragmaWarning/NumericCast.h"
    #include "System/Windows/Flags/WindowsClassStyleFlags.h"
    #include "System/Windows/Flags/WindowsFlags.h"
    #include "System/Windows/Flags/WindowsPictorialFlags.h"
    #include "System/Windows/Using/WindowsRegistryUsing.h"
    #include "System/Windows/WindowsCreate.h"
    #include "System/Windows/WindowsProcess.h"
    #include "System/Windows/WindowsRegister.h"

    #include <map>

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

    WindowsLResult SYSTEM_CALL_BACK AndroidProcess(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
    NODISCARD WindowsClassEx GetWindowClass(const String& appName) noexcept;
    MAYBE_NULLPTR WindowsHWnd CreateSystemWindow(const String& appName);

    NODISCARD WindowsLResult AppCommandEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
    NODISCARD WindowsLResult KeyInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
    NODISCARD WindowsLResult MotionInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
    NODISCARD WindowsLResult DestroyEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept;

    using EventType = WindowsLResult (*)(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
    using EventContainer = std::map<WindowsUInt, EventType>;
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
    const auto windowsName = SYSTEM_TEXT("Android Virtual Window");

    const auto hWnd = CreateSystemWindow(appName,
                                         windowsName,
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

System::WindowsLResult SYSTEM_CALL_BACK System::AndroidProcess(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    static const EventContainer eventContainer{ { EnumCastUnderlying(AppCommandType::InitWindow), &AppCommandEvent },
                                                { EnumCastUnderlying(AppCommandType::TermWindow), &AppCommandEvent },
                                                { EnumCastUnderlying(AppCommandType::WindowResized), &AppCommandEvent },
                                                { EnumCastUnderlying(AndroidKeyEventAction::Down), &KeyInputEvent },
                                                { EnumCastUnderlying(AndroidKeyEventAction::Up), &KeyInputEvent },
                                                { EnumCastUnderlying(AndroidMotionEventAction::Down), &MotionInputEvent },
                                                { EnumCastUnderlying(AndroidMotionEventAction::Up), &MotionInputEvent },
                                                { EnumCastUnderlying(AndroidMotionEventAction::Move), &MotionInputEvent },
                                                { EnumCastUnderlying(AppCommandType::Destroy), &DestroyEvent } };

    if (const auto iter = eventContainer.find(message);
        iter != eventContainer.cend())
    {
        return iter->second(hWnd, message, wParam, lParam);
    }
    else
    {
        return DefaultSystemWindowProcess(hWnd, UnderlyingCastEnum<WindowsMessages>(boost::numeric_cast<int>(message)), wParam, lParam);
    }
}

System::WindowsLResult System::AppCommandEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    systemAppCommand(mainAndroidApp, boost::numeric_cast<int32_t>(message));

    return DefaultSystemWindowProcess(hWnd, UnderlyingCastEnum<WindowsMessages>(boost::numeric_cast<int>(message)), wParam, lParam);
}

System::WindowsLResult System::KeyInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Key,
                                         UnderlyingCastEnum<AndroidKeyEventAction>(boost::numeric_cast<int>(message)),
                                         UnderlyingCastEnum<AndroidKeyCodes>(boost::numeric_cast<int>(wParam)) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hWnd, lParam);

    return 0;
}

System::WindowsLResult System::MotionInputEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    AndroidInputEvent androidInputEvent{ AndroidInputEventType::Motion, UnderlyingCastEnum<AndroidMotionEventAction>(boost::numeric_cast<int>(message)) };

    systemInputEvent(mainAndroidApp, &androidInputEvent);

    UnusedFunction(hWnd, wParam, lParam);

    return 0;
}

System::WindowsLResult System::DestroyEvent(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam) noexcept
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