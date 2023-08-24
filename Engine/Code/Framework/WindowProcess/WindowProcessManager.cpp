///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 09:19)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManager.h"
#include "Detail/WindowProcessManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Framework, WindowProcessManager)

Framework::WindowProcessManager::WindowProcessManagerUniquePtr Framework::WindowProcessManager::windowProcessManager{};

void Framework::WindowProcessManager::Create()
{
    windowProcessManager = std::make_unique<WindowProcessManager>(WindowProcessManagerCreate::Init);
}

void Framework::WindowProcessManager::Destroy() noexcept
{
    windowProcessManager.reset();
}

Framework::WindowProcessManager::WindowProcessManager(WindowProcessManagerCreate windowProcessManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(windowProcessManagerCreate);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManager)

System::WindowsProcess Framework::WindowProcessManager::GetProcess() noexcept
{
    return ImplType::GetProcess();
}

System::DisplayFunction Framework::WindowProcessManager::GetFunction() noexcept
{
    return ImplType::GetFunction();
}

bool Framework::WindowProcessManager::IsClassNameExist(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsClassNameExist(className);
}

bool Framework::WindowProcessManager::SetNewClassName(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetNewClassName(className);
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManager::GetWindowMessageInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowMessageInterface();
}

void Framework::WindowProcessManager::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetWindowMessage(windowMessage);
}

void Framework::WindowProcessManager::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->ClearWindowMessage(windowMessage);
}

bool Framework::WindowProcessManager::PreCreate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->PreCreate();
}

bool Framework::WindowProcessManager::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->Initialize();
}

void Framework::WindowProcessManager::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->PreIdle();
}

void Framework::WindowProcessManager::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->Terminate();
}

void Framework::WindowProcessManager::SetMainWindowHWnd(WindowsHWnd hWnd)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetMainWindowHWnd(hWnd);
}

Framework::WindowProcessManager::WindowsHWnd Framework::WindowProcessManager::GetMainWindowHWnd() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMainWindowHWnd();
}
