// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:54)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManager.h"
#include "Detail/WindowProcessManagerImpl.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_unique;
using std::make_shared;

SINGLETON_GET_PTR_DEFINE(Framework, WindowProcessManager)

Framework::WindowProcessManager::WindowProcessManagerUniquePtr Framework::WindowProcessManager
	::sm_WindowProcessManager{ };

void Framework::WindowProcessManager
	::Create()
{	
	sm_WindowProcessManager = make_unique<Framework::WindowProcessManager>(WindowProcessManagerCreate::Init);
}

void Framework::WindowProcessManager
	::Destroy() noexcept
{
	sm_WindowProcessManager.reset();
}

Framework::WindowProcessManager
	::WindowProcessManager(WindowProcessManagerCreate windowProcessManagerCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(windowProcessManagerCreate);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}  

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, WindowProcessManager)

// static
System::WindowProcess Framework::WindowProcessManager
	::GetProcess() noexcept
{
	return ImplType::GetProcess();
}

// static
System::DisplayFunction Framework::WindowProcessManager
	::GetFunction() noexcept
{
	return ImplType::GetFunction();
}

bool Framework::WindowProcessManager
	::IsClassNameExist(const String& className)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsClassNameExist(className);
}

bool Framework::WindowProcessManager
	::SetNewClassName(const String& className)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetNewClassName(className);
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManager
	::GetWindowMessageInterface() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;		

	return m_Impl->GetWindowMessageInterface();		
}

void Framework::WindowProcessManager
	::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	

	return m_Impl->SetWindowMessage(windowMessage);
}

void Framework::WindowProcessManager
	::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ClearWindowMessage(windowMessage);
}

bool Framework::WindowProcessManager
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreCreate(environmentDirectory);	 
}

bool Framework::WindowProcessManager
	::Initialize()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Initialize();	 
}

void Framework::WindowProcessManager
	::PreIdle()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->PreIdle();	
}

void Framework::WindowProcessManager
	::Terminate()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Terminate();	
}

void Framework::WindowProcessManager
	::SetMainWindowHwnd(HWnd hwnd)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetMainWindowHwnd(hwnd);	
}

Framework::WindowProcessManager::HWnd Framework::WindowProcessManager
	::GetMainWindowHwnd() const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26487)

	return m_Impl->GetMainWindowHwnd(); 

	#include STSTEM_WARNING_POP
}
