///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:02)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsCreate.h"
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

        NODISCARD WindowsWParam EnterMessageLoop(WindowsHWnd hwnd);

    private:
        using WindowsMsg = System::WindowsMessage;
        using CustomTime = CoreTools::CustomTime;

    private:
        NODISCARD WindowsWParam EnterOldMessageLoop() noexcept;
        NODISCARD WindowsWParam EnterNewMessageLoop(WindowsHWnd hwnd);
        NODISCARD bool ProcessingMessage(WindowsHWnd hwnd) noexcept;
        void Idle(WindowsHWnd hwnd);

    private:
        DisplayFunction function;
        CustomTime lastTime;
        WindowsMsg msg;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
