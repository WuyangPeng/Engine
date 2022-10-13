///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:29)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsProcess.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowMessageInterface
    {
    public:
        using ClassType = WindowMessageInterface;
        using HWnd = System::WindowsHWnd;
        using WParam = System::WindowsWParam;
        using LParam = System::WindowsLParam;
        using LResult = System::WindowsLResult;
        using FunctionPointer = LResult (ClassType::*)(HWnd hwnd, WParam wParam, LParam lParam);

    public:
        explicit WindowMessageInterface(int64_t delta) noexcept;
        WindowMessageInterface(int64_t delta, const EnvironmentDirectory& environmentDirectory) noexcept;
        virtual ~WindowMessageInterface() noexcept = default;
        WindowMessageInterface(const WindowMessageInterface& rhs) noexcept = default;
        WindowMessageInterface& operator=(const WindowMessageInterface& rhs) noexcept = default;
        WindowMessageInterface(WindowMessageInterface&& rhs) noexcept = default;
        WindowMessageInterface& operator=(WindowMessageInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual bool PreCreate();
        virtual bool Initialize();
        virtual void PreIdle();
        virtual void Terminate();

        virtual LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult SizeMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult CloseMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult MoveMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult CharMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult PaintMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual LResult EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam);
        virtual void Display(HWnd hwnd, int64_t timeDelta);
        NODISCARD virtual int GetTerminateKey() const noexcept;

        NODISCARD HWnd GetHwnd() const noexcept;
        void SetMainWindow(HWnd hwnd);

        NODISCARD int64_t GetDelta() const noexcept;

    private:
        HWnd windowsHwnd{ nullptr };
        int64_t delta{ 0 };
    };

    using WindowMessageInterfaceSharedPtr = std::shared_ptr<WindowMessageInterface>;
    using ConstWindowMessageInterfaceSharedPtr = std::shared_ptr<const WindowMessageInterface>;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
