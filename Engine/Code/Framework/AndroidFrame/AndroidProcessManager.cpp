///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 09:46)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcessManager.h"
#include "Detail/AndroidProcessManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

SINGLETON_GET_PTR_DEFINE(Framework, AndroidProcessManager);

std::unique_ptr<Framework::AndroidProcessManager> Framework::AndroidProcessManager::androidProcessManager{};

void Framework::AndroidProcessManager::Create()
{
    androidProcessManager = std::make_unique<Framework::AndroidProcessManager>(AndroidProcessManagerCreate::Init);
}

void Framework::AndroidProcessManager::Destroy() noexcept
{
    androidProcessManager.reset();
}

Framework::AndroidProcessManager::AndroidProcessManager(AndroidProcessManagerCreate androidProcessManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(androidProcessManagerCreate);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidProcessManager)

Framework::AndroidProcessManager::AppCmd Framework::AndroidProcessManager::GetAppCmd() noexcept
{
    return ImplType::HandleCmd;
}

Framework::AndroidProcessManager::InputEvent Framework::AndroidProcessManager::GetInputEvent() noexcept
{
    return ImplType::HandleInput;
}

Framework::AndroidProcessManager::Display Framework::AndroidProcessManager::GetDisplay() noexcept
{
    return ImplType::Display;
}

Framework::AndroidProcessManager::AndroidCallBackInterfaceSharedPtr Framework::AndroidProcessManager::GetAndroidCallBackInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return ImplType::GetAndroidCallBackInterface();
}

void Framework::AndroidProcessManager::SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::SetAndroidCallBack(androidCallBack);
}

void Framework::AndroidProcessManager::ClearAndroidCallBack()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::ClearAndroidCallBack();
}

bool Framework::AndroidProcessManager::PreCreate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::PreCreate();
}

bool Framework::AndroidProcessManager::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::Initialize();
}

void Framework::AndroidProcessManager::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::PreIdle();
}

void Framework::AndroidProcessManager::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return ImplType::Terminate();
}
