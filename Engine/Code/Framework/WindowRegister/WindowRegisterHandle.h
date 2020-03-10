// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 10:43)

// ע�ᴰ���ࣨ���ࣩ������
#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H

#include "WindowRegisterParameter.h"
#include "WindowPictorial.h"
#include "WindowName.h"
#include "System/Window/WindowProcess.h"
#include "System/Helper/UnicodeUsing.h"

#include <boost/noncopyable.hpp>
#include <string>

namespace CoreTools
{
	class CommandHandle;
}

namespace  Framework
{
	template <typename WindowProcessHandle>
	class WindowRegisterHandle : private boost::noncopyable
	{
	public:
		using ClassType = WindowRegisterHandle<WindowProcessHandle>;
		using WindowProcessType = WindowProcessHandle;
		using Command = CoreTools::CommandHandle;
		using CommandPtr = std::shared_ptr<CoreTools::CommandHandle>;
        using HInstance = System::WindowHInstance;
		using Atom = System::WindowAtom;
		using WindowClassStyleFlags = System::WindowClassStyle;

	public:
		WindowRegisterHandle(HInstance hInstance,char* lpCmdLine, const WindowPictorial& pictorial,
							 const WindowName& name, WindowClassStyleFlags styles =  System::WindowClassStyle::CommonUse);	
		virtual ~WindowRegisterHandle();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		HInstance GetHInstance() const;
		System::String GetWindowClassName() const;
		System::String GetWindowMenuName() const;
		System::DisplayPtr GetFunction() const;
		const CommandPtr GetCommandPtr() const;
		WindowProcessHandle GetWindowProcess() const;

	private:
		Atom InitApplication();
	
	private:	
		WindowProcessHandle m_WindowProcess;
		CommandPtr m_CommandPtr;
		WindowRegisterParameter m_WindowRegisterParameter;
		WindowPictorial m_WindowPictorial;		
		WindowName m_WindowName;
	};		
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_H