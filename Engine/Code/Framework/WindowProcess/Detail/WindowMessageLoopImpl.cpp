// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 10:04)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoopImpl.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMessageLoopImpl
	::WindowMessageLoopImpl(System::DisplayPtr function)
	:m_Function(function),
	 m_LastTime(),
     m_Msg()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowMessageLoopImpl)

System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterMessageLoop(HWnd hwnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

	if(m_Function != nullptr)
	{
		return EnterNewMessageLoop(hwnd);
	}
	else
	{
		return EnterOldMessageLoop();
	}
}

// private
System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterOldMessageLoop()
{
	while(System::GetSystemMessage(&m_Msg))
	{
		System::TranslateSystemMessage(&m_Msg);
		System::DispatchSystemMessage(&m_Msg);
	}

	return m_Msg.wParam;
}

// private
System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterNewMessageLoop(HWnd hwnd)
{
	// ������Ϣѭ����
    bool applicationRunning = true;

	do 
	{
		if (System::PeekSystemMessage(&m_Msg))
		{
			if(!ProcessingMessage(hwnd))
            {
               applicationRunning = false;
               continue;
            }
		}
		else
		{
			Idle(hwnd);
		}

	} while (applicationRunning);

	return m_Msg.wParam;
}

// private
bool Framework::WindowMessageLoopImpl
	::ProcessingMessage(HWnd hwnd)
{
	if (static_cast<System::WindowMessages>(m_Msg.message) == System::WindowMessages::Quit)
    { 
	    return false;
    }
			
    System::WindowHAccel accel = 0;
    if (!System::SystemTranslateAccelerator(hwnd, accel, &m_Msg))
    {
        System::TranslateSystemMessage(&m_Msg);
        System::DispatchSystemMessage(&m_Msg);
    }

	return true;
}

// private
void Framework::WindowMessageLoopImpl
	::Idle(HWnd hwnd)
{
	FRAMEWORK_ASSERTION_0(m_Function != nullptr,"���к���ָ��Ϊ�գ�");

	int64_t timeDelta = m_LastTime.GetThisElapsedMillisecondTime();
			
    m_Function(hwnd,timeDelta);
			
    System::SystemValidateRect(hwnd);
}
