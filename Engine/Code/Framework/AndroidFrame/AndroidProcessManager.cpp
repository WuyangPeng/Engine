// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:25)

#include "Framework/FrameworkExport.h"

#include "Detail/AndroidProcessManagerImpl.h"
#include "AndroidCallBackInterface.h"
#include "AndroidProcessManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CORE_TOOLS_MUTEX_EXTERN(Framework);

Framework::AndroidProcessManager* Framework::AndroidProcessManager
	::sm_AndroidProcessManager = nullptr;
CoreTools::Mutex* Framework::AndroidProcessManager
	::sm_AndroidProcessManagerMutex = nullptr;

#define MUTEX_ENTER_GLOBAL \
	    CoreTools::ScopedMutex holder(g_FrameworkMutex)

#define MUTEX_ENTER_MEMBER \
	    CoreTools::ScopedMutex holder(*sm_AndroidProcessManagerMutex)

SINGLETON_GET_PTR_DEFINE(Framework,AndroidProcessManager)

void Framework::AndroidProcessManager
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

void Framework::AndroidProcessManager
	::DoCreate()
{
	MUTEX_ENTER_GLOBAL;

	if(!sm_AndroidProcessManagerMutex)
		sm_AndroidProcessManagerMutex = new CoreTools::Mutex;

	if(!sm_AndroidProcessManager)	
		sm_AndroidProcessManager = new AndroidProcessManager;	
}

void Framework::AndroidProcessManager
	::Destroy()
{
	MUTEX_ENTER_GLOBAL;

	delete sm_AndroidProcessManager;
	sm_AndroidProcessManager = nullptr;

	delete sm_AndroidProcessManagerMutex;
	sm_AndroidProcessManagerMutex = nullptr;
}

Framework::AndroidProcessManager
	::AndroidProcessManager()
	:m_Impl(new ImplType)
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::AndroidProcessManager
	::~AndroidProcessManager()
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Framework,AndroidProcessManager)

Framework::AndroidProcessManager::AppCmd
    Framework::AndroidProcessManager
	::GetAppCmd() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->HandleCmd;
}

Framework::AndroidProcessManager::InputEvent 
	Framework::AndroidProcessManager
	::GetInputEvent() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->HandleInput;
}

Framework::AndroidProcessManager::AndroidCallBackInterfacePtr 
	Framework::AndroidProcessManager
	::GetAndroidCallBackInterfacePtr() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->GetAndroidCallBackInterfacePtr();
}

void Framework::AndroidProcessManager
	::SetAndroidCallBack( AndroidCallBackInterfacePtr ptr )
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetAndroidCallBack(ptr);
}

void Framework::AndroidProcessManager
	::ClearAndroidCallBack()
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearAndroidCallBack();
}

bool Framework::AndroidProcessManager
	::PreCreate()
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreCreate();
}

bool Framework::AndroidProcessManager
	::Initialize()
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Initialize();
}

void Framework::AndroidProcessManager
	::PreIdle()
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreIdle();
}

void Framework::AndroidProcessManager
	::Terminate()
{
	 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Terminate();
}

Framework::AndroidProcessManager::Display 
	Framework::AndroidProcessManager
	::GetDisplay() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Impl->Display;
}

