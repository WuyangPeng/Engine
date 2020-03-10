// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:21)

#include "Framework/FrameworkExport.h"

#include "Detail/OpenGLGlutProcessManagerImpl.h"
#include "OpenGLGlutProcessManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CORE_TOOLS_MUTEX_EXTERN(Framework);

#define MUTEX_ENTER_GLOBAL \
	    CoreTools::ScopedMutex holder(g_FrameworkMutex)

#define MUTEX_ENTER_MEMBER \
	    CoreTools::ScopedMutex holder(*sm_OpenGLGlutProcessManagerMutex)

Framework::OpenGLGlutProcessManager* Framework::OpenGLGlutProcessManager
	::sm_OpenGLGlutProcessManager = nullptr;

CoreTools::Mutex* Framework::OpenGLGlutProcessManager
	::sm_OpenGLGlutProcessManagerMutex = nullptr;

SINGLETON_GET_PTR_DEFINE(Framework,OpenGLGlutProcessManager)

void Framework::OpenGLGlutProcessManager
	::Create()
{
	MUTEX_ENTER_GLOBAL;

	try
	{
		DoCreate();
	}
	catch (...)
	{
		Destroy();
		throw;
	} 
}

void Framework::OpenGLGlutProcessManager
	::DoCreate()
{
	MUTEX_ENTER_GLOBAL;

	if(!sm_OpenGLGlutProcessManagerMutex)
		sm_OpenGLGlutProcessManagerMutex = new CoreTools::Mutex;

	if(!sm_OpenGLGlutProcessManager)	
		sm_OpenGLGlutProcessManager = new OpenGLGlutProcessManager;	
}

void Framework::OpenGLGlutProcessManager
	::Destroy()
{
	MUTEX_ENTER_GLOBAL;

	delete sm_OpenGLGlutProcessManager;
	sm_OpenGLGlutProcessManager = nullptr;

	delete sm_OpenGLGlutProcessManagerMutex;
	sm_OpenGLGlutProcessManagerMutex = nullptr;
}

Framework::OpenGLGlutProcessManager
	::OpenGLGlutProcessManager()
	:m_Impl(new OpenGLGlutProcessManagerImpl)
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::OpenGLGlutProcessManager
	::~OpenGLGlutProcessManager()
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_SELF_CLASS_IS_VALID_1;	
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutProcessManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if(m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Framework::OpenGLGlutProcessManager::RenderSceneCallback 
   Framework::OpenGLGlutProcessManager
   ::GetRenderSceneCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->RenderScene;
}

Framework::OpenGLGlutProcessManager::ChangeSizeCallback 
	Framework::OpenGLGlutProcessManager
	::GetChangeSizeCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->ChangeSize;
}

unsigned int Framework::OpenGLGlutProcessManager
	::GetMillisecond() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMillisecond();
}

Framework::OpenGLGlutProcessManager::TimerFunctionCallback 
	Framework::OpenGLGlutProcessManager
	::GetTimerFunctionCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->TimerFunction;
}

Framework::OpenGLGlutProcessManager::SpecialKeysDownCallback 
	Framework::OpenGLGlutProcessManager
	::GetSpecialKeysDownCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->SpecialKeysDown;
}

Framework::OpenGLGlutProcessManager::KeyboardDownCallback 
	Framework::OpenGLGlutProcessManager
	::GetKeyboardDownCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->KeyboardDown;
}

Framework::OpenGLGlutProcessManager::MouseFunctionCallback 
	Framework::OpenGLGlutProcessManager
	::GetMouseFunctionCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->MouseFunction;
}

Framework::OpenGLGlutProcessManager::MotionFunctionCallback
	Framework::OpenGLGlutProcessManager
	::GetMotionFunctionCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->MotionFunction;
}

Framework::OpenGLGlutProcessManager::IdleFunctionCallback 
	Framework::OpenGLGlutProcessManager
	::GetIdleFunctionCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IdleFunction;
}

Framework::OpenGLGlutProcessManager::ProcessMenuCallback 
	Framework::OpenGLGlutProcessManager
	::GetProcessMenuCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->ProcessMenu;
}

Framework::OpenGLGlutProcessManager::TerminateCallback 
	Framework::OpenGLGlutProcessManager
	::GetTerminateCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->TerminateFunction;
}

Framework::OpenGLGlutProcessManager::OpenGLGlutCallBackInterfacePtr 
	Framework::OpenGLGlutProcessManager
	::GetOpenGLGlutCallBackInterfacePtr() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetOpenGLGlutCallBackInterfacePtr();
}

void Framework::OpenGLGlutProcessManager
	::SetOpenGLGlutCallBack( OpenGLGlutCallBackInterfacePtr ptr )
{
 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetOpenGLGlutCallBack(ptr);
}

void Framework::OpenGLGlutProcessManager
	::ClearOpenGLGlutCallBack()
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearOpenGLGlutCallBack();
}

void Framework::OpenGLGlutProcessManager
	::SetWindowID( int window )
{
 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWindowID(window);
}

int Framework::OpenGLGlutProcessManager
	::GetWindowID() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWindowID();
}

void Framework::OpenGLGlutProcessManager
	::SetMillisecond( unsigned millisecond )
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMillisecond(millisecond);
}

void Framework::OpenGLGlutProcessManager
	::SetMainFunctionHelperPtr( MainFunctionHelperBase* ptr )
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMainFunctionHelperPtr(ptr);
}

void Framework::OpenGLGlutProcessManager
	::ClearMainFunctionHelperPtr()
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearMainFunctionHelperPtr();
}

bool Framework::OpenGLGlutProcessManager
	::PreCreate()
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreCreate();
}

bool Framework::OpenGLGlutProcessManager
	::Initialize()
{

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Initialize();
}

void Framework::OpenGLGlutProcessManager
	::PreIdle()
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreIdle();
}

void Framework::OpenGLGlutProcessManager
	::Terminate()
{
 

	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Terminate();
}

Framework::OpenGLGlutProcessManager::SpecialKeysUpCallback 
	Framework::OpenGLGlutProcessManager
	::GetSpecialKeysUpCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->SpecialKeysUp;
}

Framework::OpenGLGlutProcessManager::KeyboardUpCallback 
	Framework::OpenGLGlutProcessManager
	::GetKeyboardUpCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->KeyboardUp;
}

Framework::OpenGLGlutProcessManager::PassiveMotionFunctionCallback 
	Framework::OpenGLGlutProcessManager
	::GetPassiveMotionCallback() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->PassiveMotion;
}

Framework::MainFunctionHelperBase* Framework::OpenGLGlutProcessManager
	::GetMainFunctionHelperPtr() 
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMainFunctionHelperPtr();
}



