// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 11:33)

// 注册窗口类（基类）的实现
#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H

#include "WindowRegisterHandle.h"
#include "System/Window/WindowRegister.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename WindowProcess>
Framework::WindowRegisterHandle<WindowProcess>
	::WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory, HInstance instance, const char* commandLine, const WindowPictorial& pictorial, const WindowName& name, WindowClassStyle styles)
	:m_EnvironmentDirectory{ environmentDirectory }, m_WindowProcess{ System::g_Microseconds / sm_Interval }, m_Command{ std::make_shared<Command>(commandLine) },
	 m_WindowRegisterParameter{ instance,styles }, m_WindowPictorial{ pictorial }, m_WindowName{ name }
{
	using namespace std::literals;

	auto className = m_WindowName.GetWindowClassName();

	// 允许在创建窗口之前进行工作。
	if (!m_WindowProcess.PreCreate(environmentDirectory) ||
		m_WindowProcess.IsClassNameExist(className) ||
		InitApplication() == 0 ||
		!m_WindowProcess.SetNewClassName(className))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("注册窗口失败！"s));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowProcessHandle>
Framework::WindowRegisterHandle<WindowProcessHandle>
	::WindowRegisterHandle(WindowRegisterHandle&& rhs) noexcept
	:m_EnvironmentDirectory{ std::move(rhs.m_EnvironmentDirectory) }, m_WindowProcess{ std::move(rhs.m_WindowProcess) },
	 m_Command{ std::move(rhs.m_Command) }, m_WindowRegisterParameter{ std::move(rhs.m_WindowRegisterParameter) },
	 m_WindowPictorial{ std::move(rhs.m_WindowPictorial) }, m_WindowName{ std::move(rhs.m_WindowName) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename WindowProcessHandle>
Framework::WindowRegisterHandle<WindowProcessHandle>& Framework::WindowRegisterHandle<WindowProcessHandle>
	::operator=(WindowRegisterHandle&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_EnvironmentDirectory = std::move(rhs.m_EnvironmentDirectory);
	m_WindowProcess = std::move(rhs.m_WindowProcess);
	m_Command = std::move(rhs.m_Command);
	m_WindowRegisterParameter = std::move(rhs.m_WindowRegisterParameter);
	m_WindowPictorial = std::move(rhs.m_WindowPictorial);
	m_WindowName = std::move(rhs.m_WindowName);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename WindowProcess>
bool Framework::WindowRegisterHandle<WindowProcess>
	::IsValid() const noexcept
{
	if (m_Command != nullptr)
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
	auto wndclass = System::GetWindowsStructDefaultSize<System::WindowClassEx>();	

	auto windowClassName = m_WindowName.GetWindowClassName();
	auto windowMenuName = m_WindowName.GetWindowMenuName();

	wndclass.style = System::EnumCastUnderlying<System::WindowUInt>(m_WindowRegisterParameter.GetStyle());
	wndclass.lpfnWndProc = m_WindowProcess.GetProcess();
	wndclass.cbClsExtra = m_WindowRegisterParameter.GetWindowClassExtra();
	wndclass.cbWndExtra = m_WindowRegisterParameter.GetWindowExtra();
	wndclass.hInstance = m_WindowRegisterParameter.GetHInstance();
	wndclass.hIcon = m_WindowPictorial.GetHIcon();
	wndclass.hCursor = m_WindowPictorial.GetHCursor();
	wndclass.hbrBackground = m_WindowPictorial.GetHBrush();
	wndclass.lpszMenuName = windowMenuName.c_str();
	wndclass.lpszClassName = windowClassName.c_str();
	wndclass.hIconSm = m_WindowPictorial.GetHIcon();

	return System::RegisterSystemClass(&wndclass);
}

template <typename WindowProcess>
System::WindowHInstance Framework::WindowRegisterHandle<WindowProcess>
	::GetHInstance() const noexcept
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
typename Framework::WindowRegisterHandle<WindowProcess>::DisplayFunction Framework::WindowRegisterHandle<WindowProcess>
	::GetFunction() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowProcess.GetFunction();
}

template <typename WindowProcess>
typename Framework::WindowRegisterHandle<WindowProcess>::CommandSharedPtr Framework::WindowRegisterHandle<WindowProcess>
	::GetCommand() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Command;
}

template <typename WindowProcess>
WindowProcess Framework::WindowRegisterHandle<WindowProcess>
	::GetWindowProcess() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowProcess;
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_DETAIL_H

