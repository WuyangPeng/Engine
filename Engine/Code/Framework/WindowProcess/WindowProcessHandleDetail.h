/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:15)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_DETAIL_H

#include "WindowProcessHandle.h"
#include "WindowProcessManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>::WindowProcessHandle(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : windowMessage{ std::make_shared<WindowMessage>(delta, environmentDirectory) }
{
    WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(windowMessage);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>::~WindowProcessHandle() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    ClearWindowMessage();
}

template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>::ClearWindowMessage() const noexcept
{
    EXCEPTION_TRY
    {
        WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage(windowMessage);
    }
    EXCEPTION_ALL_CATCH(Framework)
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

template <typename WindowMessage>
typename Framework::WindowProcessHandle<WindowMessage>::WindowsProcess Framework::WindowProcessHandle<WindowMessage>::GetProcess() noexcept
{
    return WindowProcessManager::GetProcess();
}

template <typename WindowMessage>
typename Framework::WindowProcessHandle<WindowMessage>::DisplayFunction Framework::WindowProcessHandle<WindowMessage>::GetFunction() noexcept
{
    return WindowProcessManager::GetFunction();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::IsClassNameExist(const System::String& className)
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className);
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::SetNewClassName(const System::String& className)
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(className);
}

template <typename WindowMessage>
System::WindowsHWnd Framework::WindowProcessHandle<WindowMessage>::GetMainWindowHWnd()
{
    return WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHWnd();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate();
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

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_HANDLE_DETAIL_H
