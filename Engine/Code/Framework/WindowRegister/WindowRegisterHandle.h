// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 11:53)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H

#include "WindowName.h"
#include "WindowPictorial.h"
#include "WindowRegisterParameter.h"
#include "System/Window/WindowProcess.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Command/CommandFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <string>

namespace Framework
{
	// 注册窗口类（基类）的声明
	template <typename WindowProcessHandle>
	class WindowRegisterHandle
	{
	public:
		using WindowProcessType = WindowProcessHandle;
		using ClassType = WindowRegisterHandle<WindowProcessType>;
		using String = System::String;
		using Atom = System::WindowAtom;		
		using HInstance = System::WindowHInstance;	
		using DisplayFunction = System::DisplayFunction;
		using WindowClassStyle = System::WindowClassStyle;
		using Command = CoreTools::CommandHandle;
		using CommandSharedPtr = std::shared_ptr<CoreTools::CommandHandle>;

	public:
		WindowRegisterHandle(const EnvironmentDirectory& environmentDirectory, HInstance instance,const char* commandLine, const WindowPictorial& pictorial,
							 const WindowName& name, WindowClassStyle styles = WindowClassStyle::CommonUse);
		virtual ~WindowRegisterHandle() = default;
		WindowRegisterHandle(const WindowRegisterHandle& rhs) noexcept = delete;
		WindowRegisterHandle& operator=(const WindowRegisterHandle& rhs) noexcept = delete;
		WindowRegisterHandle(WindowRegisterHandle&& rhs) noexcept;
		WindowRegisterHandle& operator=(WindowRegisterHandle&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		HInstance GetHInstance() const noexcept;
		String GetWindowClassName() const;
		String GetWindowMenuName() const;
		DisplayFunction GetFunction() const noexcept;
		CommandSharedPtr GetCommand() const noexcept;
		WindowProcessHandle GetWindowProcess() const noexcept;

	private:
		Atom InitApplication();

	private:
		static constexpr auto sm_Interval = 60;

		EnvironmentDirectory m_EnvironmentDirectory;
		WindowProcessHandle m_WindowProcess;
		CommandSharedPtr m_Command;
		WindowRegisterParameter m_WindowRegisterParameter;
		WindowPictorial m_WindowPictorial;
		WindowName m_WindowName;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H