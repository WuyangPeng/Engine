// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 10:10)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManagerImpl.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMessageInterfaceSmartPointer Framework::WindowProcessManagerImpl
	::sm_WindowMessage;

Framework::WindowProcessManagerImpl::MessageFunctionPointerContainer Framework::WindowProcessManagerImpl
	::sm_FunctionPointer;

Framework::WindowProcessManagerImpl::ClassNameContainer Framework::WindowProcessManagerImpl
	::sm_ClassName;

Framework::WindowProcessManagerImpl
	::WindowProcessManagerImpl()
{
	GenerateMessage();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::WindowProcessManagerImpl
    ::GenerateMessage()
{
	sm_FunctionPointer = MessageFunctionPointerContainer{ { System::WindowMessages::Paint,&WindowMessageInterface::PaintMessage },
														  { System::WindowMessages::EraseBkgnd,&WindowMessageInterface::EraseBackgroundMessage },
														  { System::WindowMessages::Move, &WindowMessageInterface::MoveMessage },
														  { System::WindowMessages::Size, &WindowMessageInterface::SizeMessage },
														  { System::WindowMessages::Char, &WindowMessageInterface::CharMessage },
													      { System::WindowMessages::KeyDown, &WindowMessageInterface::KeyDownMessage },
														  { System::WindowMessages::KeyUp, &WindowMessageInterface::KeyUpMessage },
														  { System::WindowMessages::LButtonDown, &WindowMessageInterface::LeftButtonDownMessage },
														  { System::WindowMessages::LButtonUp, &WindowMessageInterface::LeftButtonUpMessage },
														  { System::WindowMessages::MButtonDown, &WindowMessageInterface::MiddleButtonDownMessage },
														  { System::WindowMessages::MButtonUp, &WindowMessageInterface::MiddleButtonUpMessage },
														  { System::WindowMessages::RButtonDown, &WindowMessageInterface::RightButtonDownMessage },
														  { System::WindowMessages::RButtonUp, &WindowMessageInterface::RightButtonUpMessage },
														  { System::WindowMessages::MouseMove, &WindowMessageInterface::MouseMoveMessage },
														  { System::WindowMessages::MouseWheel, &WindowMessageInterface::MouseWheelMessage },
														  { System::WindowMessages::Create, &WindowMessageInterface::CreateMessage },
														  { System::WindowMessages::Close, &WindowMessageInterface::CloseMessage },
														  { System::WindowMessages::Destroy, &WindowMessageInterface::DestroyMessage } };		 
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowProcessManagerImpl)

System::WindowProc Framework::WindowProcessManagerImpl
   ::GetProcess() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WindowProc;
}

System::DisplayPtr Framework::WindowProcessManagerImpl
	::GetFunction() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return Display;
}

Framework::ConstWindowMessageInterfaceSmartPointer Framework::WindowProcessManagerImpl
	::GetWindowMessageInterface() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_WindowMessage;
}

void Framework::WindowProcessManagerImpl
	::SetWindowMessage( const WindowMessageInterfaceSmartPointer& smartPointer )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_WindowMessage = smartPointer;
}

void Framework::WindowProcessManagerImpl
	::ClearWindowMessage()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_WindowMessage.Reset();
}

bool Framework::WindowProcessManagerImpl
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		return sm_WindowMessage->PreCreate();
	}
	else
	{
		return false;
	}
}

bool Framework::WindowProcessManagerImpl
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		return sm_WindowMessage->Initialize();
	}
	else
	{
		return false;
	}
}

void Framework::WindowProcessManagerImpl
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		return sm_WindowMessage->PreIdle();
	}
}


void Framework::WindowProcessManagerImpl
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		sm_WindowMessage->Terminate();
	}
}

System::WindowLResult Framework::WindowProcessManagerImpl
	::WindowProc( HWnd hwnd,UINT message, WParam wParam,LParam lParam )
{
	System::WindowMessages flag = static_cast<System::WindowMessages>(message); 

	MessageFunctionPointerContainerConstIter iter = sm_FunctionPointer.find(flag);

	if(sm_WindowMessage.IsValidPtr() && iter != sm_FunctionPointer.end())
	{
		return ((*sm_WindowMessage).*(iter->second))(hwnd,wParam,lParam);
	}
	else
	{
		return System::DefSystemWindowProc(hwnd,flag,wParam,lParam);
	}
}

void Framework::WindowProcessManagerImpl
	::Display( HWnd hwnd,int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		sm_WindowMessage->Display(hwnd,timeDelta);
	}
}

bool Framework::WindowProcessManagerImpl
	::SetNewClassName( const System::String& className )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_ClassName.insert(className).second)
		return true;
	else
		return false;
}

bool Framework::WindowProcessManagerImpl
	::IsClassNameExist( const System::String& className ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if(sm_ClassName.find(className) != sm_ClassName.end())
		return true;
	else
		return false;
}

void Framework::WindowProcessManagerImpl
	::SetMainWindow( HWnd hwnd )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_WindowMessage.IsValidPtr())
	{
		sm_WindowMessage->SetMainWindow(hwnd);
	}
}

Framework::WindowProcessManagerImpl::HWnd Framework::WindowProcessManagerImpl
	::GetMainWindowHwnd() const
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_0(sm_WindowMessage.IsValidPtr(),"");
	
	return sm_WindowMessage->GetHwnd();
}

