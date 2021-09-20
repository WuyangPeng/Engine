// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 21:24)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H

#include "WindowsAPIFrameBuild.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>
	::WindowsAPIFrameBuild(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
	:m_WindowRegister{ environmentDirectory, instance, commandLine,information.GetWindowPictorial(), information.GetWindowName()},
	 m_WindowCreate{ WindowInstanceParameter{ instance, m_WindowRegister.GetWindowClassName() },
					 WindowCreateParameter{ information.GetWindowTitle(),information.GetStyle() },
					 information.GetWindowSize() },
	 m_WindowMessageLoop{ m_WindowRegister.GetFunction() }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
} 

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>
	::WindowsAPIFrameBuild(WindowsAPIFrameBuild&& rhs) noexcept
	:m_WindowRegister{ std::move(rhs.m_WindowRegister) }, 
	 m_WindowCreate{ std::move(rhs.m_WindowCreate) }, 
	 m_WindowMessageLoop{ std::move(rhs.m_WindowMessageLoop) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename Process>
Framework::WindowsAPIFrameBuild<Process>& Framework::WindowsAPIFrameBuild<Process>
	::operator=(WindowsAPIFrameBuild&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_WindowRegister = std::move(rhs.m_WindowRegister);
	m_WindowCreate = std::move(rhs.m_WindowCreate);
	m_WindowMessageLoop = std::move(rhs.m_WindowMessageLoop);

	return *this;
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
System::WindowsHWnd Framework::WindowsAPIFrameBuild<Process>
	::GetHwnd() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowCreate.GetHwnd();
}

template <typename Process>
System::WindowsHInstance Framework::WindowsAPIFrameBuild<Process>
	::GetHInstance() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowRegister.GetHInstance();
}

template <typename Process>
int Framework::WindowsAPIFrameBuild<Process>
	::EnterMessageLoop()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	using namespace std::literals;

	auto process = m_WindowRegister.GetWindowProcess();

	if (process.Initialize())
	{
		// 默认PreIdle()清除缓冲区。允许应用程序填充他们的窗口在窗口显示之后和事件循环开始之前。
		process.PreIdle();

		const auto result = m_WindowMessageLoop.EnterMessageLoop(m_WindowCreate.GetHwnd());

		process.Terminate();

		return boost::numeric_cast<int>(result);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("进程初始化失败！"s));
	}
}

#endif // FRAMEWORK_WINDOWS_API_FRAME_BUILD_DETAIL_H





