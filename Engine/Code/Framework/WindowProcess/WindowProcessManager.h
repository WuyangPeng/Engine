// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:02)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/WindowProcess.h"
#include "WindowMessageInterface.h" 

FRAMEWORK_EXPORT_SHARED_PTR(WindowProcessManagerImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace CoreTools
{
	class Mutex;	
}

namespace Framework
{	
	class FRAMEWORK_DEFAULT_DECLARE WindowProcessManager : public CoreTools::Singleton<WindowProcessManager>
	{	
		SINGLETON_INITIALIZE_DECLARE(WindowProcessManager);	 

	public:
		using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;
		using WndProc = System::WindowProc;
		using HWnd = System::WindowHWnd;
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;	

	public:			
		WndProc GetProcess() const;
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
		SINGLETON_MEMBER_DECLARE(WindowProcessManager); 
	};
}

#define WINDOW_PROCESS_MANAGER_SINGLETON Framework::WindowProcessManager::GetSingleton()

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
