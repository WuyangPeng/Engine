///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:52)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcessManager.h"
#include "Detail/AndroidProcessManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_unique;
using std::unique_ptr;
using namespace std::literals;

SINGLETON_GET_PTR_DEFINE(Framework, AndroidProcessManager);

unique_ptr<Framework::AndroidProcessManager> Framework::AndroidProcessManager::androidProcessManager{};

void Framework::AndroidProcessManager::Create()
{
    androidProcessManager = make_unique<Framework::AndroidProcessManager>(AndroidProcessManagerCreate::Init);
}

void Framework::AndroidProcessManager::Destroy() noexcept
{
    androidProcessManager.reset();
}

Framework::AndroidProcessManager::AndroidProcessManager(MAYBE_UNUSED AndroidProcessManagerCreate androidProcessManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
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

    return impl->GetAndroidCallBackInterface();
}

void Framework::AndroidProcessManager::SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetAndroidCallBack(androidCallBack);
}

void Framework::AndroidProcessManager::ClearAndroidCallBack()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->ClearAndroidCallBack();
}

bool Framework::AndroidProcessManager::PreCreate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->PreCreate();
}

bool Framework::AndroidProcessManager::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->Initialize();
}

void Framework::AndroidProcessManager::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->PreIdle();
}

void Framework::AndroidProcessManager::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->Terminate();
}
