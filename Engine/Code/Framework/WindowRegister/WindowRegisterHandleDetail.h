// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:37)

// 注册窗口类（基类）的实现
#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H

#include "WindowRegisterHandle.h"
#include "System/Window/WindowRegister.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename WindowProcess>
Framework::WindowRegisterHandle<WindowProcess>
	::WindowRegisterHandle(HInstance hInstance,char* lpCmdLine,const WindowPictorial& pictorial, const WindowName& name, WindowClassStyleFlags styles)
	:m_WindowProcess(),m_CommandPtr(new Command(lpCmdLine)),
     m_WindowRegisterParameter(hInstance,styles),
	 m_WindowPictorial(pictorial),
	 m_WindowName(name)
{
	System::String className = m_WindowName.GetWindowClassName();

	// 允许在创建窗口之前进行工作。
	if(!m_WindowProcess.PreCreate() || 
	   m_WindowProcess.IsClassNameExist(className) ||
	   InitApplication() == 0 ||
	   !m_WindowProcess.SetNewClassName(className))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("注册窗口失败！"));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowProcess>
Framework::WindowRegisterHandle<WindowProcess>
	::~WindowRegisterHandle()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename WindowProcess>
bool Framework::WindowRegisterHandle<WindowProcess>
	::IsValid() const noexcept
{
	if(m_CommandPtr != nullptr)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <typename WindowProcess>
System::WindowAtom Framework::WindowRegisterHandle<WindowProcess>
	::InitApplication()
{
	System::WindowClassEx wndclass { 0,0,nullptr,0,0,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr };

	wndclass.cbSize = sizeof(System::WindowClassEx);
	wndclass.style = static_cast<System::WindowUInt>(m_WindowRegisterParameter.GetStyle());
	wndclass.lpfnWndProc = m_WindowProcess.GetProcess();
	wndclass.cbClsExtra = m_WindowRegisterParameter.GetWindowClassExtra();
	wndclass.cbWndExtra = m_WindowRegisterParameter.GetWindowExtra();
	wndclass.hInstance = m_WindowRegisterParameter.GetHInstance();
	wndclass.hIcon = m_WindowPictorial.GetHIcon();
	wndclass.hCursor = m_WindowPictorial.GetHCursor();
	wndclass.hbrBackground = m_WindowPictorial.GetHBrush();
	wndclass.lpszMenuName = m_WindowName.GetWindowMenuName().c_str();
	wndclass.lpszClassName = m_WindowName.GetWindowClassName().c_str();
	wndclass.hIconSm = m_WindowPictorial.GetHIcon();

	return System::RegisterSystemClass(&wndclass);
}

template <typename WindowProcess>
System::WindowHInstance Framework::WindowRegisterHandle<WindowProcess>
	:: GetHInstance() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowRegisterParameter.GetHInstance();
}

template <typename WindowProcess>
System::String Framework::WindowRegisterHandle<WindowProcess>
	::GetWindowClassName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowName.GetWindowClassName();
}

template <typename WindowProcess>
System::String Framework::WindowRegisterHandle<WindowProcess>
	::GetWindowMenuName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowName.GetWindowMenuName();
}

template <typename WindowProcess>
System::DisplayPtr Framework::WindowRegisterHandle<WindowProcess>
	::GetFunction() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowProcess.GetFunction();
}

template <typename WindowProcess>
const typename Framework::WindowRegisterHandle<WindowProcess>::CommandPtr Framework::WindowRegisterHandle<WindowProcess>
	::GetCommandPtr() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_CommandPtr;
}

template <typename WindowProcess>
WindowProcess Framework::WindowRegisterHandle<WindowProcess>
	::GetWindowProcess() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowProcess;
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H

