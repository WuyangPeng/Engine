/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:15)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Time/CustomTime.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowMessageLoopImpl
    {
    public:
        using ClassType = WindowMessageLoopImpl;

        using WindowsHWnd = System::WindowsHWnd;
        using WindowsWParam = System::WindowsWParam;
        using DisplayFunction = System::DisplayFunction;

    public:
        explicit WindowMessageLoopImpl(DisplayFunction function) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WindowsWParam EnterMessageLoop(WindowsHWnd hWnd);

    private:
        using WindowsMsg = System::WindowsMessage;
        using CustomTime = CoreTools::CustomTime;

    private:
        NODISCARD WindowsWParam EnterOldMessageLoop() noexcept;
        NODISCARD WindowsWParam EnterNewMessageLoop(WindowsHWnd hWnd);
        NODISCARD bool ProcessingMessage(WindowsHWnd hWnd);
        void Idle(WindowsHWnd hWnd) noexcept;

    private:
        DisplayFunction function;
        CustomTime lastTime;
        WindowsMsg msg;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
