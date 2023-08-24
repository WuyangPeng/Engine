///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 09:17)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

FRAMEWORK_EXPORT_UNIQUE_PTR(WindowProcessManager);
FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowProcessManagerImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowProcessManager : public CoreTools::Singleton<WindowProcessManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(WindowProcessManager);
        using ParentType = Singleton<WindowProcessManager>;

        using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;
        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsProcess = System::WindowsProcess;
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
        NODISCARD static WindowsProcess GetProcess() noexcept;
        NODISCARD static DisplayFunction GetFunction() noexcept;
        NODISCARD bool IsClassNameExist(const String& className);
        NODISCARD bool SetNewClassName(const String& className);

        NODISCARD ConstWindowMessageInterfaceSharedPtr GetWindowMessageInterface() const;

        void SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);
        void ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);

        bool PreCreate();
        bool Initialize();
        void PreIdle();
        void Terminate();

        void SetMainWindowHWnd(WindowsHWnd hWnd);
        NODISCARD WindowsHWnd GetMainWindowHWnd() const;

    private:
        using WindowProcessManagerUniquePtr = std::unique_ptr<WindowProcessManager>;

    private:
        static WindowProcessManagerUniquePtr windowProcessManager;
        PackageType impl;
    };
}

#define WINDOW_PROCESS_MANAGER_SINGLETON Framework::WindowProcessManager::GetSingleton()

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_H
