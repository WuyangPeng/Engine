///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:03)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H

#include "WindowMessageInterface.h"
#include "Framework/MiddleLayer/MiddleLayerInternalFwd.h"
#include "Framework/WindowCreate/WindowPoint.h"

namespace Framework
{
    template <typename MiddleLayer>
    class WindowMessage : public WindowMessageInterface
    {
    public:
        using MiddleLayerType = MiddleLayer;
        using ClassType = WindowMessage<MiddleLayerType>;
        using ParentType = WindowMessageInterface;
        using String = System::String;

    public:
        WindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool PreCreate() override;
        NODISCARD bool Initialize() override;
        void PreIdle() override;
        void Terminate() override;

        LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult SizeMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult CloseMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult CharMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult MoveMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult PaintMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        LResult EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
        void Display(HWnd hwnd, int64_t timeDelta) override;

    private:
        void DoCloseMessage(HWnd hwnd) const;
        NODISCARD String GetWindowsClassName(HWnd hwnd) const;
        NODISCARD WindowPoint GetCursorPosition(HWnd hwnd) const noexcept;
        NODISCARD bool IsSpecialKey(int virtualKey) const noexcept;

    private:
        MiddleLayerInterfaceSharedPtr middleLayer;
        int64_t accumulative;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
