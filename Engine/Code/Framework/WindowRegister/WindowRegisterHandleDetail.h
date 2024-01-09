///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 19:25)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H

#include "WindowRegisterHandle.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename WindowsProcess>
Framework::WindowRegisterHandle<WindowsProcess>::WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory, HInstance instance, const char* commandLine, WindowPictorial pictorial, WindowName name, WindowsClassStyle styles)
    : environmentDirectory{ environmentDirectory },
      windowProcess{ System::gMillisecond / interval, environmentDirectory },
      command{ std::make_shared<CommandHandle>(commandLine) },
      windowRegisterParameter{ instance, styles },
      windowPictorial{ std::move(pictorial) },
      windowName{ std::move(name) }
{
    Init();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowProcessHandle>
Framework::WindowRegisterHandle<WindowProcessHandle>::WindowRegisterHandle(WindowRegisterHandle&& rhs) noexcept
    : environmentDirectory{ std::move(rhs.environmentDirectory) },
      windowProcess{ std::move(rhs.windowProcess) },
      command{ std::move(rhs.command) },
      windowRegisterParameter{ std::move(rhs.windowRegisterParameter) },
      windowPictorial{ std::move(rhs.windowPictorial) },
      windowName{ std::move(rhs.windowName) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowProcessHandle>
Framework::WindowRegisterHandle<WindowProcessHandle>& Framework::WindowRegisterHandle<WindowProcessHandle>::operator=(WindowRegisterHandle&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    environmentDirectory = std::move(rhs.environmentDirectory);
    windowProcess = std::move(rhs.windowProcess);
    command = std::move(rhs.command);
    windowRegisterParameter = std::move(rhs.windowRegisterParameter);
    windowPictorial = std::move(rhs.windowPictorial);
    windowName = std::move(rhs.windowName);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename WindowsProcess>
bool Framework::WindowRegisterHandle<WindowsProcess>::IsValid() const noexcept
{
    if (command != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename WindowProcessHandle>
void Framework::WindowRegisterHandle<WindowProcessHandle>::Init()
{
    // 允许在创建窗口之前进行工作。
    if (const auto className = windowName.GetWindowClassName();
        !windowProcess.PreCreate() ||
        windowProcess.IsClassNameExist(className) ||
        InitApplication() == 0 ||
        !windowProcess.SetNewClassName(className))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("注册窗口失败！"s))
    }
}

template <typename WindowsProcess>
System::WindowsAtom Framework::WindowRegisterHandle<WindowsProcess>::InitApplication()
{
    auto windowsClass = System::GetWindowsStructDefaultSize<System::WindowsClassEx>();

    const auto windowClassName = windowName.GetWindowClassName();
    const auto windowMenuName = windowName.GetWindowMenuName();

    windowsClass.style = System::EnumCastUnderlying<System::WindowsUInt>(windowRegisterParameter.GetStyle());
    windowsClass.lpfnWndProc = windowProcess.GetProcess();
    windowsClass.cbClsExtra = windowRegisterParameter.GetWindowClassExtra();
    windowsClass.cbWndExtra = windowRegisterParameter.GetWindowExtra();
    windowsClass.hInstance = windowRegisterParameter.GetHInstance();
    windowsClass.hIcon = windowPictorial.GetHIcon();
    windowsClass.hCursor = windowPictorial.GetHCursor();
    windowsClass.hbrBackground = windowPictorial.GetHBrush();
    windowsClass.lpszMenuName = windowMenuName.c_str();
    windowsClass.lpszClassName = windowClassName.c_str();
    windowsClass.hIconSm = windowPictorial.GetHIcon();

    return System::RegisterSystemClass(&windowsClass);
}

template <typename WindowsProcess>
System::WindowsHInstance Framework::WindowRegisterHandle<WindowsProcess>::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowRegisterParameter.GetHInstance();
}

template <typename WindowsProcess>
System::String Framework::WindowRegisterHandle<WindowsProcess>::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowName.GetWindowClassName();
}

template <typename WindowsProcess>
System::String Framework::WindowRegisterHandle<WindowsProcess>::GetWindowMenuName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowName.GetWindowMenuName();
}

template <typename WindowsProcess>
typename Framework::WindowRegisterHandle<WindowsProcess>::DisplayFunction Framework::WindowRegisterHandle<WindowsProcess>::GetFunction() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowProcess.GetFunction();
}

template <typename WindowsProcess>
typename Framework::WindowRegisterHandle<WindowsProcess>::CommandHandleSharedPtr Framework::WindowRegisterHandle<WindowsProcess>::GetCommand() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return command;
}

template <typename WindowsProcess>
WindowsProcess Framework::WindowRegisterHandle<WindowsProcess>::GetWindowProcess() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowProcess;
}

template <typename WindowsProcess>
Framework::EnvironmentDirectory Framework::WindowRegisterHandle<WindowsProcess>::GetEnvironmentDirectory() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return environmentDirectory;
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H
