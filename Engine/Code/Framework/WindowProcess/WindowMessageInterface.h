/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:28)

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
        using FunctionPointer = LResult (ClassType::*)(HWnd hWnd, WParam wParam, LParam lParam);

    public:
        /// WindowMessageInterface未使用EnvironmentDirectory参数，
        /// 保留这个重载是需要统一WindowMessage的构造函数。
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

        NODISCARD virtual LResult CreateMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult SizeMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult CloseMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult MoveMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult CharMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult KeyDownMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult KeyUpMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult LeftButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult LeftButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult MiddleButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult MiddleButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult RightButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult RightButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult MouseMoveMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult MouseWheelMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult DestroyMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult PaintMessage(HWnd hWnd, WParam wParam, LParam lParam);
        NODISCARD virtual LResult EraseBackgroundMessage(HWnd hWnd, WParam wParam, LParam lParam);
        virtual void Display(HWnd hWnd, int64_t timeDelta);
        NODISCARD virtual int GetTerminateKey() const noexcept;

        NODISCARD HWnd GetHWnd() const noexcept;
        void SetMainWindow(HWnd hWnd);

        NODISCARD int64_t GetDelta() const noexcept;

    private:
        HWnd windowsHWnd;
        int64_t delta;
    };

    using WindowMessageInterfaceSharedPtr = std::shared_ptr<WindowMessageInterface>;
    using ConstWindowMessageInterfaceSharedPtr = std::shared_ptr<const WindowMessageInterface>;

}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
