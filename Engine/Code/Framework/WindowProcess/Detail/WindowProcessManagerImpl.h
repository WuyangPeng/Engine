///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:02)

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
        using HWnd = System::WindowsHWnd;
        using UInt = System::WindowsUInt;
        using WParam = System::WindowsWParam;
        using LParam = System::WindowsLParam;
        using LResult = System::WindowsLResult;
        using WindowProcess = System::WindowsProcess;
        using WindowMessages = System::WindowsMessages;
        using DisplayFunction = System::DisplayFunction;
        using MessageFunctionPointer = WindowMessageInterface::FunctionPointer;

    public:
        CLASS_INVARIANT_DECLARE;

        WindowProcessManagerImpl() noexcept;

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

        void SetMainWindowHwnd(HWnd hwnd);
        NODISCARD HWnd GetMainWindowHwnd() const noexcept;

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
