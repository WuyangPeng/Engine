///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:47)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManager.h"
#include "Detail/WindowProcessManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Framework, WindowProcessManager)

Framework::WindowProcessManager::WindowProcessManagerUniquePtr Framework::WindowProcessManager::windowProcessManager{};

void Framework::WindowProcessManager::Create()
{
    windowProcessManager = make_unique<Framework::WindowProcessManager>(WindowProcessManagerCreate::Init);
}

void Framework::WindowProcessManager::Destroy() noexcept
{
    windowProcessManager.reset();
}

Framework::WindowProcessManager::WindowProcessManager(MAYBE_UNUSED WindowProcessManagerCreate windowProcessManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManager)

// static
System::WindowsProcess Framework::WindowProcessManager::GetProcess() noexcept
{
    return ImplType::GetProcess();
}

// static
System::DisplayFunction Framework::WindowProcessManager::GetFunction() noexcept
{
    return ImplType::GetFunction();
}

bool Framework::WindowProcessManager::IsClassNameExist(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsClassNameExist(className);
}

bool Framework::WindowProcessManager::SetNewClassName(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetNewClassName(className);
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManager::GetWindowMessageInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetWindowMessageInterface();
}

void Framework::WindowProcessManager::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetWindowMessage(windowMessage);
}

void Framework::WindowProcessManager::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->ClearWindowMessage(windowMessage);
}

bool Framework::WindowProcessManager::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->PreCreate(environmentDirectory);
}

bool Framework::WindowProcessManager::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Initialize();
}

void Framework::WindowProcessManager::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->PreIdle();
}

void Framework::WindowProcessManager::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->Terminate();
}

void Framework::WindowProcessManager::SetMainWindowHwnd(HWnd hwnd)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->SetMainWindowHwnd(hwnd);
}

Framework::WindowProcessManager::HWnd Framework::WindowProcessManager::GetMainWindowHwnd() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetMainWindowHwnd();
}
