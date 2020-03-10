// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 10:14)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManager.h"
#include "Detail/WindowProcessManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_MUTEX_DEFINE(Framework,WindowProcessManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder(g_FrameworkMutex)

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder(*sm_WindowProcessManagerMutex)

SINGLETON_INITIALIZE_DEFINE(Framework,WindowProcessManager)
SINGLETON_DEFINE(Framework,WindowProcessManager)

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowProcessManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if(m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowProc Framework::WindowProcessManager
	::GetProcess() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetProcess();
}

System::DisplayPtr Framework::WindowProcessManager
	::GetFunction() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetFunction();
}

Framework::ConstWindowMessageInterfaceSmartPointer Framework::WindowProcessManager
	::GetWindowMessageInterface() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWindowMessageInterface();
}

void Framework::WindowProcessManager
	::SetWindowMessage( const WindowMessageInterfaceSmartPointer& smartPointer )
{
	 MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetWindowMessage(smartPointer);
}

void Framework::WindowProcessManager
	::ClearWindowMessage()
{ 
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearWindowMessage();
}

bool Framework::WindowProcessManager
	::PreCreate()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreCreate();
}

bool Framework::WindowProcessManager
	::Initialize()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Initialize();
}

void Framework::WindowProcessManager
	::PreIdle()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreIdle();
}

void Framework::WindowProcessManager
	::Terminate()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Terminate();
}

bool Framework::WindowProcessManager
	::IsClassNameExist( const System::String& className ) const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsClassNameExist(className);
}

bool Framework::WindowProcessManager
	::SetNewClassName( const System::String& className )
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->SetNewClassName(className);
}

void Framework::WindowProcessManager
	::SetMainWindow( HWnd hwnd )
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMainWindow(hwnd);
}

Framework::WindowProcessManager::HWnd Framework::WindowProcessManager
	::GetMainWindowHwnd() const
{
	MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMainWindowHwnd();
}

