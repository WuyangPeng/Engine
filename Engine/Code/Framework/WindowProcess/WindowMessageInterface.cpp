// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:14)

#include "Framework/FrameworkExport.h"

#include "WindowMessageInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "Framework/Application/ApplicationTrait.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Window/Flags/WindowMessagesFlags.h"

Framework::WindowMessageInterface
	::WindowMessageInterface()
	:m_Hwnd(nullptr)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowMessageInterface
	::~WindowMessageInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowMessageInterface)

System::WindowLResult Framework::WindowMessageInterface
    ::CreateMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	
	// 只保存第一个创建窗口的HWnd
	if(m_Hwnd == nullptr)
	{
		m_Hwnd = hwnd;
	}

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Create,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::SizeMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");
	
	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Size,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::CloseMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Close,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::CharMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Char, wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::KeyDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");
	
	return System::DefSystemWindowProc(hwnd,System::WindowMessages::KeyDown,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::KeyUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::KeyUp,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::LeftButtonDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::LButtonDown,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::LeftButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::LButtonUp,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::MiddleButtonDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::MButtonDown,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::MiddleButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::MButtonUp, wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::RightButtonDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::RButtonDown,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::RightButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::RButtonUp, wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::MouseMoveMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");
	
	return System::DefSystemWindowProc(hwnd,System::WindowMessages::MouseMove,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::MouseWheelMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::MouseWheel,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::DestroyMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	// 只收到主窗口销毁时才退出程序。
	if(hwnd == m_Hwnd)
	{
		m_Hwnd = nullptr;

		return System::PostSystemQuitMessage();
	}
	else
	{		
		return System::DefSystemWindowProc(hwnd,System::WindowMessages::Destroy,wParam,lParam);
	}
}

System::WindowLResult Framework::WindowMessageInterface
	::PaintMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Paint, wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::EraseBackgroundMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	return System::DefSystemWindowProc(hwnd,System::WindowMessages::EraseBkgnd,wParam,lParam);
}

System::WindowLResult Framework::WindowMessageInterface
	::MoveMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");
	
	return System::DefSystemWindowProc(hwnd,System::WindowMessages::Move, wParam,lParam);
}

void Framework::WindowMessageInterface
	::Display( HWnd hwnd,int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(timeDelta);
}

System::WindowHWnd Framework::WindowMessageInterface
	::GetHwnd() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Hwnd;
}

bool Framework::WindowMessageInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::WindowMessageInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

void Framework::WindowMessageInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

void Framework::WindowMessageInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

uint8_t Framework::WindowMessageInterface
	::GetTerminateKey() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return static_cast<uint8_t>(WindowApplicationTrait::KeyIdentifiers::sm_KeyTerminate);
}

void Framework::WindowMessageInterface
	::SetMainWindow( HWnd hwnd )
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr,"窗口还未创建！");

	// 修改主窗口
	m_Hwnd = hwnd;
}

