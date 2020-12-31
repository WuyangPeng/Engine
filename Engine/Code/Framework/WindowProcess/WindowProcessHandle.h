// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 10:50)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H

#include "System/Window/WindowProcess.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h" 

#include <type_traits> 

namespace Framework
{
	template <typename WindowMessage>
	class WindowProcessHandle
	{
	public:
		static_assert(std::is_base_of_v<WindowMessageInterface, WindowMessage>);

	public:
		using MessageType = WindowMessage;
		using ClassType = WindowProcessHandle<MessageType>;
		using String = System::String;
		using HWnd = System::WindowHWnd;
		using WindowProcess = System::WindowProcess;
		using DisplayFunction = System::DisplayFunction;

	public:
		explicit WindowProcessHandle(int64_t delta);
		virtual ~WindowProcessHandle() noexcept;
		WindowProcessHandle(const WindowProcessHandle& rhs) noexcept = default;
		WindowProcessHandle& operator=(const WindowProcessHandle& rhs) noexcept = default;
		WindowProcessHandle(WindowProcessHandle&& rhs) noexcept = default;
		WindowProcessHandle& operator=(WindowProcessHandle&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	public:
		static WindowProcess GetProcess() noexcept;
		static DisplayFunction GetFunction() noexcept;

		static bool IsClassNameExist(const String& className);
		static bool SetNewClassName(const String& className);

		static HWnd GetMainWindowHwnd();

		virtual bool PreCreate(const EnvironmentDirectory& environmentDirectory);
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

	private:
		void ClearWindowMessage();

	private:
		WindowMessageInterfaceSharedPtr m_WindowMessage;
	};

	using WindowProcessInterface = WindowProcessHandle<WindowMessageInterface>;
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
