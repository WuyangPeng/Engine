// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:01)

// 窗口过程类的声明 
#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H

#include "System/Window/WindowProcess.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
 
#include <type_traits>
#include <string>

namespace Framework
{
	class WindowMessageInterface;

	template <typename WindowMessage>
	class WindowProcessHandle 
	{
	public:
		static_assert(std::is_base_of<WindowMessageInterface,WindowMessage>::value);
	
	public:	
		using MessageType = WindowMessage;
		using ClassType = WindowProcessHandle<MessageType>;
		using WindowMessageInterfacePtr = std::shared_ptr<WindowMessageInterface>;
		using HWnd = System::WindowHWnd;

	public:
		WindowProcessHandle();		
		virtual ~WindowProcessHandle();

		CLASS_INVARIANT_VIRTUAL_DECLARE;		

	public:	
		System::WindowProc GetProcess() const;
		System::DisplayPtr GetFunction() const;

		bool PreCreate();
		bool Initialize();
		void PreIdle();
		void Terminate();

		bool IsClassNameExist(const System::String& className) const;
		bool SetNewClassName(const System::String& className);

		HWnd GetMainWindowHwnd() const;
	};

	using WindowProcessInterface = WindowProcessHandle<WindowMessageInterface>;
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_H
