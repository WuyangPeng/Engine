// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:50)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h" 
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h" 

FRAMEWORK_EXPORT_UNIQUE_PTR(WindowProcessManager);
FRAMEWORK_EXPORT_SHARED_PTR(WindowProcessManagerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowProcessManager : public CoreTools::Singleton<WindowProcessManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowProcessManager);
		using ParentType = Singleton<WindowProcessManager>;
		using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;
		using String = System::String;
		using HWnd = System::WindowHWnd;
		using WindowProcess = System::WindowProcess;
		using DisplayFunction = System::DisplayFunction;

	private:
		enum class WindowProcessManagerCreate
		{
			Init,
		};

	public:
		explicit WindowProcessManager(WindowProcessManagerCreate windowProcessManagerCreate);

		static void Create();
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(WindowProcessManager);

		CLASS_INVARIANT_DECLARE;

	public:
		static WindowProcess GetProcess() noexcept;
		static DisplayFunction GetFunction() noexcept;
		bool IsClassNameExist(const String& className);
		bool SetNewClassName(const String& className);

		ConstWindowMessageInterfaceSharedPtr GetWindowMessageInterface() const;

		void SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);
		void ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);

		bool PreCreate(const EnvironmentDirectory& environmentDirectory);
		bool Initialize();
		void PreIdle();
		void Terminate();

		void SetMainWindowHwnd(HWnd hwnd);
		HWnd GetMainWindowHwnd() const;

	private:
		using WindowProcessManagerUniquePtr = std::unique_ptr<WindowProcessManager>;

	private:
		static WindowProcessManagerUniquePtr sm_WindowProcessManager;
		IMPL_TYPE_DECLARE(WindowProcessManager);
	};
}

#define WINDOW_PROCESS_MANAGER_SINGLETON Framework::WindowProcessManager::GetSingleton()

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
