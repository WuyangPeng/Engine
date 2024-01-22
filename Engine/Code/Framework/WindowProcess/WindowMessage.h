/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:28)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "Framework/MiddleLayer/MiddleLayerInternalFwd.h"
#include "Framework/WindowCreate/WindowPoint.h"

namespace Framework
{
    template <typename MiddleLayer>
    class WindowMessage : public WindowMessageInterface
    {
    public:
        using ClassType = WindowMessage<MiddleLayer>;

        using ParentType = WindowMessageInterface;
        using String = System::String;

    public:
        WindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool PreCreate() override;
        NODISCARD bool Initialize() override;
        void PreIdle() override;
        void Terminate() override;

        NODISCARD LResult CreateMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult SizeMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult CloseMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult CharMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult MoveMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult KeyDownMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult KeyUpMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult LeftButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult LeftButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult MiddleButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult MiddleButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult RightButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult RightButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult MouseMoveMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult MouseWheelMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult DestroyMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult PaintMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        NODISCARD LResult EraseBackgroundMessage(HWnd hWnd, WParam wParam, LParam lParam) override;
        void Display(HWnd hWnd, int64_t timeDelta) override;

    private:
        void DoCloseMessage(HWnd hWnd) const;
        NODISCARD String GetWindowsClassName(HWnd hWnd) const;
        NODISCARD WindowPoint GetCursorPosition(HWnd hWnd) const noexcept;
        NODISCARD bool IsSpecialKey(int virtualKey) const noexcept;

    private:
        using MiddleLayerInterfaceSharedPtr = std::shared_ptr<MiddleLayerInterface>;

    private:
        MiddleLayerInterfaceSharedPtr middleLayer;
        int64_t accumulative;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
