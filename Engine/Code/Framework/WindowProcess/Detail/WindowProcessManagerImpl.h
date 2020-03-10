// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:52)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H

#include "System/Window/WindowProcess.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "Framework/WindowProcess/WindowMessageInterface.h"

#include <string>
#include <map>
#include <set>

namespace Framework
{	
	class FRAMEWORK_HIDDEN_DECLARE WindowProcessManagerImpl
	{	
	public:
		using ClassType = WindowProcessManagerImpl;
		using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;
		using HWnd = System::WindowHWnd;
		using WParam = System::WindowWParam;
		using LParam = System::WindowLParam;
		using UInt = System::WindowUInt;
		using LResult = System::WindowLResult;

	public:
		WindowProcessManagerImpl();
		
		CLASS_INVARIANT_DECLARE;	

	public:
		System::WindowProc GetProcess() const;
		System::DisplayPtr GetFunction() const;
		ConstWindowMessageInterfaceSmartPointer GetWindowMessageInterface() const;

		void SetWindowMessage(const WindowMessageInterfaceSmartPointer& smartPointer);
		void ClearWindowMessage();	

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

		bool IsClassNameExist(const System::String& className) const;
		bool SetNewClassName(const System::String& className);
		
		void SetMainWindow(HWnd hwnd);
		HWnd GetMainWindowHwnd() const;

	private:
		using MessageFunctionPointerContainer = std::map<System::WindowMessages,MessageFunctionPointer>;
		using MessageFunctionPointerContainerConstIter = MessageFunctionPointerContainer::const_iterator;
		using ClassNameContainer = std::set<System::String>;

	private:
		static LResult SYSTEM_CALL_BACK WindowProc(HWnd hwnd,UInt message,WParam wParam,LParam lParam);
		static void Display(HWnd hwnd,int64_t timeDelta);	
		static void GenerateMessage();		

	private:
		static MessageFunctionPointerContainer sm_FunctionPointer;
		static WindowMessageInterfaceSmartPointer sm_WindowMessage;
		static ClassNameContainer sm_ClassName;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
