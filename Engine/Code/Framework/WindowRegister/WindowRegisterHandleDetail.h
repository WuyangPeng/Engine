///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:01)

// 注册窗口类（基类）的实现
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
Framework::WindowRegisterHandle<WindowsProcess>::WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory, HInstance instance, const char* commandLine, const WindowPictorial& pictorial, const WindowName& name, WindowsClassStyle styles)
    : environmentDirectory{ environmentDirectory },
      windowProcess{ System::gMicroseconds / interval, environmentDirectory },
      command{ std::make_shared<Command>(commandLine) },
      windowRegisterParameter{ instance, styles },
      windowPictorial{ pictorial },
      windowName{ name }
{
    using namespace std::literals;

    auto className = windowName.GetWindowClassName();

    // 允许在创建窗口之前进行工作。
    if (!windowProcess.PreCreate() ||
        windowProcess.IsClassNameExist(className) ||
        InitApplication() == 0 ||
        !windowProcess.SetNewClassName(className))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("注册窗口失败！"s));
    }

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

// private
template <typename WindowsProcess>
System::WindowsAtom Framework::WindowRegisterHandle<WindowsProcess>::InitApplication()
{
    auto wndclass = System::GetWindowsStructDefaultSize<System::WindowsClassEx>();

    auto windowClassName = windowName.GetWindowClassName();
    auto windowMenuName = windowName.GetWindowMenuName();

    wndclass.style = System::EnumCastUnderlying<System::WindowsUInt>(windowRegisterParameter.GetStyle());
    wndclass.lpfnWndProc = windowProcess.GetProcess();
    wndclass.cbClsExtra = windowRegisterParameter.GetWindowClassExtra();
    wndclass.cbWndExtra = windowRegisterParameter.GetWindowExtra();
    wndclass.hInstance = windowRegisterParameter.GetHInstance();
    wndclass.hIcon = windowPictorial.GetHIcon();
    wndclass.hCursor = windowPictorial.GetHCursor();
    wndclass.hbrBackground = windowPictorial.GetHBrush();
    wndclass.lpszMenuName = windowMenuName.c_str();
    wndclass.lpszClassName = windowClassName.c_str();
    wndclass.hIconSm = windowPictorial.GetHIcon();

    return System::RegisterSystemClass(&wndclass);
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
typename Framework::WindowRegisterHandle<WindowsProcess>::CommandSharedPtr Framework::WindowRegisterHandle<WindowsProcess>::GetCommand() const noexcept
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
