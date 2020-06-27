// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.2 (2020/06/06 20:57)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowProcess.h"
#include "Framework/WindowProcess/WindowMessageInterface.h"

#include <map>
#include <set> 
#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowProcessManagerImpl
	{
	public:
		using ClassType = WindowProcessManagerImpl;
		using String = System::String;
		using HWnd = System::WindowHWnd;
		using UInt = System::WindowUInt;
		using WParam = System::WindowWParam;
		using LParam = System::WindowLParam;
		using LResult = System::WindowLResult;
		using WindowProcess = System::WindowProcess;
		using WindowMessages = System::WindowMessages;
		using DisplayFunction = System::DisplayFunction;
		using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		static WindowProcess GetProcess() noexcept;
		static DisplayFunction GetFunction() noexcept;

		static bool IsClassNameExist(const String& className);
		static bool SetNewClassName(const String& className);

		ConstWindowMessageInterfaceSharedPtr GetWindowMessageInterface() const noexcept;
		void SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);
		void ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);

		bool PreCreate(const EnvironmentDirectory& environmentDirectory);
		bool Initialize();
		void PreIdle();
		void Terminate();

		void SetMainWindowHwnd(HWnd hwnd);
		HWnd GetMainWindowHwnd() const noexcept;

	private:
		using MessageFunctionPointerContainer = std::map<WindowMessages, MessageFunctionPointer>;
		using MessageFunctionPointerContainerSharedPtr = std::shared_ptr<MessageFunctionPointerContainer>;
		using ClassNameContainer = std::set<String>;
		using ClassNameContainerSharedPtr = std::shared_ptr<ClassNameContainer>;
		using WindowMessageInterfaceWeakPtr = std::weak_ptr<WindowMessageInterface>;
		using WindowMessageContainer = std::map<int, WindowMessageInterfaceWeakPtr, std::greater<int>>;
		using WindowMessageContainerSharedPtr = std::shared_ptr<WindowMessageContainer>;

	private:
		static LResult SYSTEM_CALL_BACK WindowProc(HWnd hwnd, UInt message, WParam wParam, LParam lParam);
		static void Display(HWnd hwnd, int64_t timeDelta);
		static MessageFunctionPointerContainerSharedPtr GetMessageFunctionPointer();
		static ClassNameContainerSharedPtr GetClassNameContainer();
		static WindowMessageContainerSharedPtr GetWindowMessageContainer();

		void ResetMainWindowMessage();
		void ClearWindowMessageContainer(const WindowMessageInterfaceSharedPtr& windowMessage);		

	private:
		static WindowMessageInterfaceSharedPtr sm_WindowMessage;
		static int sm_WindowMessageIndex;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
