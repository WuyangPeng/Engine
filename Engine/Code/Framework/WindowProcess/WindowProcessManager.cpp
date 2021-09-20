// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:54)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManager.h"
#include "Detail/WindowProcessManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(Framework, WindowProcessManager)

Framework::WindowProcessManager::WindowProcessManagerUniquePtr Framework::WindowProcessManager ::sm_WindowProcessManager{};

void Framework::WindowProcessManager ::Create()
{
    sm_WindowProcessManager = make_unique<Framework::WindowProcessManager>(WindowProcessManagerCreate::Init);
}

void Framework::WindowProcessManager ::Destroy() noexcept
{
    sm_WindowProcessManager.reset();
}

Framework::WindowProcessManager ::WindowProcessManager([[maybe_unused]] WindowProcessManagerCreate windowProcessManagerCreate)
    : impl{0}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManager)

// static
System::WindowsProcess Framework::WindowProcessManager ::GetProcess() noexcept
{
    return ImplType::GetProcess();
}

// static
System::DisplayFunction Framework::WindowProcessManager ::GetFunction() noexcept
{
    return ImplType::GetFunction();
}

bool Framework::WindowProcessManager ::IsClassNameExist(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->IsClassNameExist(className);
}

bool Framework::WindowProcessManager ::SetNewClassName(const String& className)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->SetNewClassName(className);
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManager ::GetWindowMessageInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetWindowMessageInterface();
}

void Framework::WindowProcessManager ::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->SetWindowMessage(windowMessage);
}

void Framework::WindowProcessManager ::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->ClearWindowMessage(windowMessage);
}

bool Framework::WindowProcessManager ::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->PreCreate(environmentDirectory);
}

bool Framework::WindowProcessManager ::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->Initialize();
}

void Framework::WindowProcessManager ::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->PreIdle();
}

void Framework::WindowProcessManager ::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->Terminate();
}

void Framework::WindowProcessManager ::SetMainWindowHwnd(HWnd hwnd)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->SetMainWindowHwnd(hwnd);
}

Framework::WindowProcessManager::HWnd Framework::WindowProcessManager ::GetMainWindowHwnd() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)

    return impl->GetMainWindowHwnd();

#include STSTEM_WARNING_POP
}
