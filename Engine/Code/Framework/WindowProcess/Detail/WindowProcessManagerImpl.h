///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 14:01)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsProcess.h"
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
        using WindowsHWnd = System::WindowsHWnd;
        using WindowsUInt = System::WindowsUInt;
        using WindowsWParam = System::WindowsWParam;
        using WindowsLParam = System::WindowsLParam;
        using WindowsLResult = System::WindowsLResult;
        using WindowProcess = System::WindowsProcess;
        using WindowMessages = System::WindowsMessages;
        using DisplayFunction = System::DisplayFunction;
        using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;

    public:
        CLASS_INVARIANT_DECLARE;

        WindowProcessManagerImpl() noexcept = default;

    public:
        NODISCARD static WindowProcess GetProcess() noexcept;
        NODISCARD static DisplayFunction GetFunction() noexcept;

        NODISCARD static bool IsClassNameExist(const String& className);
        NODISCARD static bool SetNewClassName(const String& className);

        NODISCARD ConstWindowMessageInterfaceSharedPtr GetWindowMessageInterface() const noexcept;
        void SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);
        void ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage);

        NODISCARD bool PreCreate();
        NODISCARD bool Initialize();
        void PreIdle();
        void Terminate();

        void SetMainWindowHWnd(WindowsHWnd hWnd);
        NODISCARD WindowsHWnd GetMainWindowHWnd() const noexcept;

    private:
        using MessageFunctionPointerContainer = std::map<WindowMessages, MessageFunctionPointer>;
        using MessageFunctionPointerContainerSharedPtr = std::shared_ptr<MessageFunctionPointerContainer>;
        using ClassNameContainer = std::set<String>;
        using ClassNameContainerSharedPtr = std::shared_ptr<ClassNameContainer>;
        using WindowMessageInterfaceWeakPtr = std::weak_ptr<WindowMessageInterface>;
        using WindowMessageContainer = std::map<int, WindowMessageInterfaceWeakPtr, std::greater<>>;
        using WindowMessageContainerSharedPtr = std::shared_ptr<WindowMessageContainer>;

    private:
        static WindowsLResult SYSTEM_CALL_BACK WindowProcessFunction(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
        static WindowsLResult SYSTEM_CALL_BACK DoWindowProcessFunction(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);
        static void Display(WindowsHWnd hWnd, int64_t timeDelta);
        NODISCARD static MessageFunctionPointerContainerSharedPtr GetMessageFunctionPointer();
        NODISCARD static ClassNameContainerSharedPtr GetClassNameContainer();
        NODISCARD static WindowMessageContainerSharedPtr GetWindowMessageContainer();

        void ResetMainWindowMessage();
        void ClearWindowMessageContainer(const WindowMessageInterfaceSharedPtr& windowMessage);

    private:
        static WindowMessageInterfaceSharedPtr windowProcessMessage;
        static int windowMessageIndex;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_MANAGER_IMPL_H
