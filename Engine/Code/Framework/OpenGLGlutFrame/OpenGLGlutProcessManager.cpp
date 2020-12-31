// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:59)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManager.h"
#include "Detail/OpenGLGlutProcessManagerImpl.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_unique;
using std::make_shared;
using namespace std::literals;

SINGLETON_GET_PTR_DEFINE(Framework, OpenGLGlutProcessManager);

Framework::OpenGLGlutProcessManager::OpenGLGlutProcessManagerUniquePtr Framework::OpenGLGlutProcessManager
	::sm_OpenGLGlutProcessManager{ };

void Framework::OpenGLGlutProcessManager
	::Create()
{	
	sm_OpenGLGlutProcessManager = make_unique<Framework::OpenGLGlutProcessManager>(OpenGLGlutProcessManagerCreate::Init);	
}

void Framework::OpenGLGlutProcessManager
	::Destroy() noexcept
{
	sm_OpenGLGlutProcessManager.reset();
}

Framework::OpenGLGlutProcessManager ::OpenGLGlutProcessManager([[maybe_unused]] OpenGLGlutProcessManagerCreate openGLGlutProcessManagerCreate)
    : m_Impl{ make_shared<ImplType>() }
{
 

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, OpenGLGlutProcessManager)

Framework::OpenGLGlutProcessManager::RenderSceneCallback Framework::OpenGLGlutProcessManager
	::GetRenderSceneCallback() noexcept
{
	return ImplType::RenderScene;
}

Framework::OpenGLGlutProcessManager::ChangeSizeCallback Framework::OpenGLGlutProcessManager
	::GetChangeSizeCallback() noexcept
{
	return ImplType::ChangeSize;
}

Framework::OpenGLGlutProcessManager::TimerFunctionCallback Framework::OpenGLGlutProcessManager
	::GetTimerFunctionCallback() noexcept
{
	return ImplType::TimerFunction;
}

Framework::OpenGLGlutProcessManager::SpecialKeysDownCallback Framework::OpenGLGlutProcessManager
	::GetSpecialKeysDownCallback() noexcept
{
	return ImplType::SpecialKeysDown;
}

Framework::OpenGLGlutProcessManager::KeyboardDownCallback Framework::OpenGLGlutProcessManager
	::GetKeyboardDownCallback() noexcept
{
	return ImplType::KeyboardDown;
}

Framework::OpenGLGlutProcessManager::MouseFunctionCallback Framework::OpenGLGlutProcessManager
	::GetMouseFunctionCallback() noexcept
{
	return ImplType::MouseFunction;
}

Framework::OpenGLGlutProcessManager::MotionFunctionCallback Framework::OpenGLGlutProcessManager
	::GetMotionFunctionCallback() noexcept
{
	return ImplType::MotionFunction;
}

Framework::OpenGLGlutProcessManager::IdleFunctionCallback Framework::OpenGLGlutProcessManager
	::GetIdleFunctionCallback() noexcept
{
	return ImplType::IdleFunction;
}

Framework::OpenGLGlutProcessManager::ProcessMenuCallback Framework::OpenGLGlutProcessManager
	::GetProcessMenuCallback() noexcept
{
	return ImplType::ProcessMenu;
}

Framework::OpenGLGlutProcessManager::TerminateCallback Framework::OpenGLGlutProcessManager
	::GetTerminateCallback() noexcept
{
	return ImplType::TerminateFunction;
}

Framework::OpenGLGlutProcessManager::SpecialKeysUpCallback Framework::OpenGLGlutProcessManager
	::GetSpecialKeysUpCallback() noexcept
{
	return ImplType::SpecialKeysUp;
}

Framework::OpenGLGlutProcessManager::KeyboardUpCallback Framework::OpenGLGlutProcessManager
	::GetKeyboardUpCallback() noexcept
{
	return ImplType::KeyboardUp;
}

Framework::OpenGLGlutProcessManager::PassiveMotionFunctionCallback Framework::OpenGLGlutProcessManager
	::GetPassiveMotionCallback() noexcept
{
	return ImplType::PassiveMotion;
}

Framework::OpenGLGlutProcessManager::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManager
	::GetOpenGLGlutCallBackInterface() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetOpenGLGlutCallBack();
}

void Framework::OpenGLGlutProcessManager
	::SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetOpenGLGlutCallBack(openGLGlutCallBack);
}

void Framework::OpenGLGlutProcessManager
	::ClearOpenGLGlutCallBack()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearOpenGLGlutCallBack();
}

void Framework::OpenGLGlutProcessManager
	::SetWindowID(int window)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWindowID(window);
}

int Framework::OpenGLGlutProcessManager
	::GetWindowID() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWindowID();
}

int Framework::OpenGLGlutProcessManager
	::GetMillisecond() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMillisecond();
}

void Framework::OpenGLGlutProcessManager
	::SetMillisecond(int millisecond)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMillisecond(millisecond);
}

void Framework::OpenGLGlutProcessManager
	::SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMainFunctionHelper(mainFunctionHelperBase);
}

void Framework::OpenGLGlutProcessManager
	::ClearMainFunctionHelper()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearMainFunctionHelper();
}

Framework::OpenGLGlutProcessManager::MainFunctionHelperBaseSharedPtr Framework::OpenGLGlutProcessManager
	::GetMainFunctionHelper()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMainFunctionHelper();
}

bool Framework::OpenGLGlutProcessManager
	::PreCreate()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreCreate();
}

bool Framework::OpenGLGlutProcessManager
	::Initialize()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Initialize();
}

void Framework::OpenGLGlutProcessManager
	::PreIdle()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreIdle();
}

void Framework::OpenGLGlutProcessManager
	::Terminate()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Terminate();
}
