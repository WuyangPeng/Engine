// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 13:16)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H

#include "CoreTools/Helper/ExceptionMacro.h"
#include "WindowsAPIFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>
	::WindowsAPIFrameBuild(HInstance hInstance,char* lpCmdLine,
	                       const WindowApplicationInformation& information,
						   const System::String& className,const WindowPictorial& pictorial)
	:m_WindowRegister(hInstance,lpCmdLine,pictorial,
	                  WindowName(className)),
	 m_WindowCreate(WindowInstanceParameter(hInstance,m_WindowRegister.GetWindowClassName()),
	                WindowCreateParameter(information.GetWindowTitle(),
					                      information.GetStyle()),
					WindowSize(information.GetWindowSize())),
	 m_WindowMessageLoop(m_WindowRegister.GetFunction())
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>
	::~WindowsAPIFrameBuild()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Process>
bool Framework::WindowsAPIFrameBuild<Process>
	::IsValid() const noexcept
{ 
	  return true; 
}
#endif // OPEN_CLASS_INVARIANT

template <typename Process>
System::WindowHWnd Framework::WindowsAPIFrameBuild<Process>
	::GetHwnd() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowCreate.GetHwnd();
}

template <typename Process>
System::WindowHInstance Framework::WindowsAPIFrameBuild<Process>
	::GetHInstance() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowRegister.GetHInstance();
}

template <typename Process>
System::WindowWParam Framework::WindowsAPIFrameBuild<Process>
	::EnterMessageLoop()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	Process process = m_WindowRegister.GetWindowProcess();

	if(process.Initialize())
	{
		// Ĭ��PreIdle()�����������
		// ����Ӧ�ó���������ǵĴ�����
		// ������ʾ֮����¼�ѭ����ʼ֮ǰ��
		process.PreIdle();

		WParam returnValue =
			m_WindowMessageLoop.EnterMessageLoop(m_WindowCreate.GetHwnd());

		process.Terminate();

		return returnValue;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("���̳�ʼ��ʧ�ܣ�"));
	}
}

#endif // FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H





