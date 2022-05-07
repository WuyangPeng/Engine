///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:15)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H

#include "WindowProcessHandle.h"
#include "WindowProcessManager.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>::WindowProcessHandle(int64_t delta)
    : windowMessage{ std::make_shared<MessageType>(delta) }
{
    WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(windowMessage);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>::~WindowProcessHandle() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::ClearWindowMessage);
}

// private
template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>::ClearWindowMessage()
{
    WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage(windowMessage);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::IsValid() const noexcept
{
    if (windowMessage != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

// static
template <typename WindowMessage>
typename Framework::WindowProcessHandle<WindowMessage>::WindowsProcess Framework::WindowProcessHandle<WindowMessage>::GetProcess() noexcept
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.GetProcess();
}

// static
template <typename WindowMessage>
typename Framework::WindowProcessHandle<WindowMessage>::DisplayFunction Framework::WindowProcessHandle<WindowMessage>::GetFunction() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.GetFunction();
}

// static
template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::IsClassNameExist(const System::String& className)
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className);
}

// static
template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::SetNewClassName(const System::String& className)
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(className);
}

// static
template <typename WindowMessage>
System::WindowsHWnd Framework::WindowProcessHandle<WindowMessage>::GetMainWindowHwnd()
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate(environmentDirectory);
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.Initialize();
}

template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.PreIdle();
}

template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.Terminate();
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H
