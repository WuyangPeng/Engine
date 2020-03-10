// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 09:39)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandleImpl.h"
#include "System/Window/WindowCreate.h"
#include "Framework/WindowProcess/WindowProcessManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateHandleImpl
	::WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
	:m_WindowInstanceParameter(windowInstanceParameter),
	 m_WindowCreateParameter(windowCreateParameter),
	 m_Size(size),m_Hwnd(nullptr)
{
	InitInstance();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowCreateHandleImpl
	::InitInstance()
{
	// Ҫ�󴰿���ָ���Ŀͻ�����С��
	RECT rect = { 0, 0,  m_Size.GetWindowWidth() - 1, m_Size.GetWindowHeight() - 1 };

	if(!System::AdjustSystemWindowRect(&rect, m_WindowCreateParameter.GetStyle()))
    {
		THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ڴ�Сʧ�ܣ�"));	
    }
	
	// ����Ӧ�ó��򴰿ڡ�
	m_Hwnd = System::CreateSystemWindow(m_WindowInstanceParameter.GetWindowClassName().c_str(),  
		                                m_WindowCreateParameter.GetWindowsName().c_str(), 
						                m_WindowCreateParameter.GetStyle(),
										m_WindowCreateParameter.GetLeftTopCorner().GetWindowX(), 
										m_WindowCreateParameter.GetLeftTopCorner().GetWindowY(),
										rect,m_WindowCreateParameter.GetParent(), 
										m_WindowCreateParameter.GetMenu(),  
										m_WindowInstanceParameter.GetHInstance()); 

	if(m_Hwnd == nullptr)
    {
		THROW_EXCEPTION(SYSTEM_TEXT("��������ʧ�ܣ�"));	
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowCreateHandleImpl
    ::IsValid() const noexcept
{
	if(m_Hwnd != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

Framework::WindowCreateHandleImpl::HWnd Framework::WindowCreateHandleImpl
    ::GetHwnd() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Hwnd;
}

void Framework::WindowCreateHandleImpl
	::SetMainWindow()
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;
	
	WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindow(m_Hwnd);
}
