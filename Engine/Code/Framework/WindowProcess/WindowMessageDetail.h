// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 09:45)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H

#include "WindowMessage.h"
#include "VirtualKeysTypes.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Window/WindowUser.h"
#include "System/Window/WindowCreate.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "Framework/WindowCreate/WindowSize.h"

template <typename MiddleLayer>
Framework::WindowMessage<MiddleLayer>
	::WindowMessage()
	:m_MiddleLayerPtr(NEW0 MiddleLayerType), m_TimeDelta(System::g_Microseconds / 60)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename MiddleLayer>
Framework::WindowMessage<MiddleLayer>
	::~WindowMessage()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && m_MiddleLayerPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::CreateMessage(HWnd hwnd, WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayerPtr->Create();

	return ParentType::CreateMessage(hwnd,wParam,lParam);		
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::SizeMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	WindowSize clientSize(lParam);	
	System::WindowDisplay flag(static_cast<System::WindowDisplay>(wParam));	
	m_MiddleLayerPtr->Resize(flag,clientSize);

	return ParentType::SizeMessage(hwnd,wParam,lParam);		
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::CloseMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	DoCloseMessage(hwnd);

	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;  
}

// private
template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::DoCloseMessage( HWnd hwnd ) const
{
	System::String className(GetWindowsClassName(hwnd));
	
	System::String exitInformation = SYSTEM_TEXT("是否退出") + className + SYSTEM_TEXT("？");	

	if(System::MessageBox(hwnd,exitInformation,className))
	{
		System::DestroySystemWindow(hwnd);
	}
}

// private
template <typename MiddleLayer>
System::String Framework::WindowMessage<MiddleLayer>
	::GetWindowsClassName(HWnd hwnd) const
{	
    System::String name;

	if(System::GetWindowTextString(hwnd,name))	
		return name;	
	else	
		return SYSTEM_TEXT("程序");			
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::CharMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	uint8_t key = static_cast<uint8_t>(wParam);

	// 当Terminate键被按下时退出应用程序。
	if (key == GetTerminateKey())
	{
		System::SendSystemMessage(hwnd, System::WindowMessages::Close, 0, 0);		
	}
	else
	{
		// 获取客户端光标的位置。
		WindowPoint point = GetCursorPosition(hwnd);

		m_MiddleLayerPtr->KeyDown(key,point);			
	}

	SYSTEM_UNUSED_ARG(lParam);

	return 0;	
}

// private
template <typename MiddleLayer>
const Framework::WindowPoint Framework::WindowMessage<MiddleLayer>
	::GetCursorPosition( HWnd hwnd ) const
{
	System::WindowPoint point;
	System::GetCursorClientPos(hwnd, point);

	return WindowPoint(point);
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::KeyDownMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int virtKey = static_cast<int>(wParam);

	// 获取客户端光标的位置。
	WindowPoint point = GetCursorPosition(hwnd);

	if (IsSpecialKey(virtKey))
	{
		m_MiddleLayerPtr->SpecialKeyDown(virtKey, point);
	}

	SYSTEM_UNUSED_ARG(lParam);

	return 0;		
}

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::IsSpecialKey(int virtKey) const
{
	if ((static_cast<int>(System::WindowsKeyCodes::F1) <= virtKey &&
		virtKey <= static_cast<int>(System::WindowsKeyCodes::F12)) ||
		(static_cast<int>(System::WindowsKeyCodes::Prior) <= virtKey &&
		virtKey <= static_cast<int>(System::WindowsKeyCodes::Down)) ||
		(virtKey == static_cast<int>(System::WindowsKeyCodes::Insert)) ||
		(virtKey == static_cast<int>(System::WindowsKeyCodes::Delete)) ||
		(virtKey == static_cast<int>(System::WindowsKeyCodes::Shift)) ||
		(virtKey == static_cast<int>(System::WindowsKeyCodes::Control)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::KeyUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int virtKey = static_cast<int>(wParam);

	// 获取客户端光标的位置。
	WindowPoint point = GetCursorPosition(hwnd);

	if (IsSpecialKey(virtKey))
	{
		m_MiddleLayerPtr->SpecialKeyUp(virtKey, point);
	}
	else
	{
		m_MiddleLayerPtr->KeyUp(static_cast<unsigned char>(virtKey),   point);
	}

	SYSTEM_UNUSED_ARG(lParam);

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::LeftButtonDownMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesLeftButton,  MouseStateTypesMouseDown, WindowPoint(lParam), virtualKeys);
	
	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::LeftButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesLeftButton, MouseStateTypesMouseUp, WindowPoint(lParam), virtualKeys);
	
	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MiddleButtonDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesMiddleButton, MouseStateTypesMouseDown, WindowPoint(lParam), virtualKeys);
	
	SYSTEM_UNUSED_ARG(hwnd);

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MiddleButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesMiddleButton,  MouseStateTypesMouseUp, WindowPoint(lParam), virtualKeys);

	SYSTEM_UNUSED_ARG(hwnd);

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::RightButtonDownMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesRightButton, MouseStateTypesMouseDown, WindowPoint(lParam), virtualKeys);
	
	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::RightButtonUpMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	m_MiddleLayerPtr->MouseClick(MouseButtonsTypesRightButton, MouseStateTypesMouseUp, WindowPoint(lParam), virtualKeys);

	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MouseMoveMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	VirtualKeysTypes virtualKeys(wParam);

	if (virtualKeys.IsMouseDown())
	{
		m_MiddleLayerPtr->Motion(WindowPoint(lParam),virtualKeys);
	}
	else
	{
		m_MiddleLayerPtr->PassiveMotion(WindowPoint(lParam));
	}	
	
	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MouseWheelMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	
	VirtualKeysTypes virtualKeys(System::GetLowWord(wParam));

	m_MiddleLayerPtr->MouseWheel(System::GetHighWord(wParam) / static_cast<int>(System::WindowMessages::MouseWheel), WindowPoint(lParam), virtualKeys);

	SYSTEM_UNUSED_ARG(hwnd);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::DestroyMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayerPtr->Destroy();

	return ParentType::DestroyMessage(hwnd,wParam,lParam);	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::PaintMessage(HWnd hwnd,WParam wParam,LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::WindowPaintStruct ps;
	System::SystemBeginPaint(hwnd, &ps);
	m_MiddleLayerPtr->Paint();	
	System::SystemEndPaint(hwnd, &ps);

	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;	
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MoveMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayerPtr->Move(WindowPoint(lParam));

	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(wParam);

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::EraseBackgroundMessage( HWnd hwnd,WParam wParam, LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	// 这告诉Windows不擦除背景（由OpenGL或DirectX来完成）。
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 1;
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::Display(HWnd hwnd,int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayerPtr->Idle(timeDelta);

	m_TimeDelta -= timeDelta;

	if (m_TimeDelta <= 0)
	{
		// TODO 这里临时加上刷新窗口的语句。
		System::SystemInvalidateRect(hwnd);
		System::UpdateSystemWindows(hwnd);

		m_TimeDelta += System::g_Microseconds / 60;
	}
	
	return ParentType::Display(hwnd,timeDelta);
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
