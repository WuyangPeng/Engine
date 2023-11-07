///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 15:03)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManager.h"
#include "Detail/OpenGLGlutProcessManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Framework, OpenGLGlutProcessManager);

Framework::OpenGLGlutProcessManager::OpenGLGlutProcessManagerUniquePtr Framework::OpenGLGlutProcessManager::openGLGlutProcessManager{};

void Framework::OpenGLGlutProcessManager::Create()
{
    openGLGlutProcessManager = std::make_unique<Framework::OpenGLGlutProcessManager>(OpenGLGlutProcessManagerCreate::Init);
}

void Framework::OpenGLGlutProcessManager::Destroy() noexcept
{
    openGLGlutProcessManager.reset();
}

Framework::OpenGLGlutProcessManager::OpenGLGlutProcessManager(OpenGLGlutProcessManagerCreate openGLGlutProcessManagerCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(openGLGlutProcessManagerCreate);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, OpenGLGlutProcessManager)

Framework::OpenGLGlutProcessManager::RenderSceneCallback Framework::OpenGLGlutProcessManager::GetRenderSceneCallback() noexcept
{
    return ImplType::RenderScene;
}

Framework::OpenGLGlutProcessManager::ChangeSizeCallback Framework::OpenGLGlutProcessManager::GetChangeSizeCallback() noexcept
{
    return ImplType::ChangeSize;
}

Framework::OpenGLGlutProcessManager::TimerFunctionCallback Framework::OpenGLGlutProcessManager::GetTimerFunctionCallback() noexcept
{
    return ImplType::TimerFunction;
}

Framework::OpenGLGlutProcessManager::SpecialKeysDownCallback Framework::OpenGLGlutProcessManager::GetSpecialKeysDownCallback() noexcept
{
    return ImplType::SpecialKeysDown;
}

Framework::OpenGLGlutProcessManager::KeyboardDownCallback Framework::OpenGLGlutProcessManager::GetKeyboardDownCallback() noexcept
{
    return ImplType::KeyboardDown;
}

Framework::OpenGLGlutProcessManager::MouseFunctionCallback Framework::OpenGLGlutProcessManager::GetMouseFunctionCallback() noexcept
{
    return ImplType::MouseFunction;
}

Framework::OpenGLGlutProcessManager::MotionFunctionCallback Framework::OpenGLGlutProcessManager::GetMotionFunctionCallback() noexcept
{
    return ImplType::MotionFunction;
}

Framework::OpenGLGlutProcessManager::IdleFunctionCallback Framework::OpenGLGlutProcessManager::GetIdleFunctionCallback() noexcept
{
    return ImplType::IdleFunction;
}

Framework::OpenGLGlutProcessManager::ProcessMenuCallback Framework::OpenGLGlutProcessManager::GetProcessMenuCallback() noexcept
{
    return ImplType::ProcessMenu;
}

Framework::OpenGLGlutProcessManager::TerminateCallback Framework::OpenGLGlutProcessManager::GetTerminateCallback() noexcept
{
    return ImplType::TerminateFunction;
}

Framework::OpenGLGlutProcessManager::SpecialKeysUpCallback Framework::OpenGLGlutProcessManager::GetSpecialKeysUpCallback() noexcept
{
    return ImplType::SpecialKeysUp;
}

Framework::OpenGLGlutProcessManager::KeyboardUpCallback Framework::OpenGLGlutProcessManager::GetKeyboardUpCallback() noexcept
{
    return ImplType::KeyboardUp;
}

Framework::OpenGLGlutProcessManager::PassiveMotionFunctionCallback Framework::OpenGLGlutProcessManager::GetPassiveMotionCallback() noexcept
{
    return ImplType::PassiveMotion;
}

Framework::OpenGLGlutProcessManager::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManager::GetOpenGLGlutCallBackInterface() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return ImplType::GetOpenGLGlutCallBack();
}

void Framework::OpenGLGlutProcessManager::SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::SetOpenGLGlutCallBack(openGLGlutCallBack);
}

void Framework::OpenGLGlutProcessManager::ClearOpenGLGlutCallBack()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::ClearOpenGLGlutCallBack();
}

void Framework::OpenGLGlutProcessManager::SetWindowId(int window)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::SetWindowId(window);
}

int Framework::OpenGLGlutProcessManager::GetWindowId() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return ImplType::GetWindowId();
}

int Framework::OpenGLGlutProcessManager::GetMillisecond() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return ImplType::GetMillisecond();
}

void Framework::OpenGLGlutProcessManager::SetMillisecond(int millisecond)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::SetMillisecond(millisecond);
}

void Framework::OpenGLGlutProcessManager::SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelper)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::SetMainFunctionHelper(mainFunctionHelper);
}

void Framework::OpenGLGlutProcessManager::ClearMainFunctionHelper()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::ClearMainFunctionHelper();
}

Framework::OpenGLGlutProcessManager::MainFunctionHelperBaseSharedPtr Framework::OpenGLGlutProcessManager::GetMainFunctionHelper()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return ImplType::GetMainFunctionHelper();
}

bool Framework::OpenGLGlutProcessManager::PreCreate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::PreCreate();
}

bool Framework::OpenGLGlutProcessManager::Initialize()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::Initialize();
}

void Framework::OpenGLGlutProcessManager::PreIdle()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::PreIdle();
}

void Framework::OpenGLGlutProcessManager::Terminate()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    FRAMEWORK_CLASS_IS_VALID_1;

    return ImplType::Terminate();
}
