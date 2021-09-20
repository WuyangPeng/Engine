// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:42)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcessManager.h"
#include "Detail/AndroidProcessManagerImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::shared_ptr;
using namespace std::literals;

CORE_TOOLS_MUTEX_EXTERN(Framework);
SINGLETON_GET_PTR_DEFINE(Framework, AndroidProcessManager);

shared_ptr<Framework::AndroidProcessManager> Framework::AndroidProcessManager ::sm_AndroidProcessManager{};

void Framework::AndroidProcessManager ::Create()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

    if (sm_AndroidProcessManager == nullptr)
    {
        sm_AndroidProcessManager = make_shared<Framework::AndroidProcessManager>(AndroidProcessManagerCreate::Init);
    }
}

void Framework::AndroidProcessManager ::Destroy()
{
    SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

    sm_AndroidProcessManager.reset();
}

Framework::AndroidProcessManager ::AndroidProcessManager([[maybe_unused]] AndroidProcessManagerCreate androidProcessManagerCreate)
    : impl{ std::make_shared<AndroidProcessManagerImpl>() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidProcessManager ::~AndroidProcessManager() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::DestroyImpl);
}

// private
void Framework::AndroidProcessManager ::DestroyImpl()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    impl.reset();
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidProcessManager)

Framework::AndroidProcessManager::AppCmd Framework::AndroidProcessManager ::GetAppCmd() noexcept
{
    return ImplType::HandleCmd;
}

Framework::AndroidProcessManager::InputEvent Framework::AndroidProcessManager ::GetInputEvent() noexcept
{
    return ImplType::HandleInput;
}

Framework::AndroidProcessManager::Display Framework::AndroidProcessManager ::GetDisplay() noexcept
{
    return ImplType::Display;
}

Framework::AndroidProcessManager::AndroidCallBackInterfaceSharedPtr Framework::AndroidProcessManager ::GetAndroidCallBackInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetAndroidCallBackInterface();
}

void Framework::AndroidProcessManager ::SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->SetAndroidCallBack(androidCallBack);
}

void Framework::AndroidProcessManager ::ClearAndroidCallBack()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->ClearAndroidCallBack();
}

bool Framework::AndroidProcessManager ::PreCreate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->PreCreate();
}

bool Framework::AndroidProcessManager ::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->Initialize();
}

void Framework::AndroidProcessManager ::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->PreIdle();
}

void Framework::AndroidProcessManager ::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    ;

    return impl->Terminate();
}
