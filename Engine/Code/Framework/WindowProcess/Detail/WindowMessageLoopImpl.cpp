///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:08)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoopImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::WindowMessageLoopImpl::WindowMessageLoopImpl(DisplayFunction function) noexcept
    : function{ function }, lastTime{}, msg{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoopImpl)

System::WindowsWParam Framework::WindowMessageLoopImpl::EnterMessageLoop(WindowsHWnd hwnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (function != nullptr)
    {
        return EnterNewMessageLoop(hwnd);
    }
    else
    {
        return EnterOldMessageLoop();
    }
}

// private
System::WindowsWParam Framework::WindowMessageLoopImpl::EnterOldMessageLoop() noexcept
{
    while (System::GetSystemMessage(&msg))
    {
        System::TranslateSystemMessage(&msg);
        System::DispatchSystemMessage(&msg);
    }

    return msg.wParam;
}

// private
System::WindowsWParam Framework::WindowMessageLoopImpl::EnterNewMessageLoop(WindowsHWnd hwnd)
{
    // 启动消息循环。
    auto applicationRunning = true;

    do
    {
        if (System::PeekSystemMessage(&msg))
        {
            if (!ProcessingMessage(hwnd))
            {
                applicationRunning = false;
                continue;
            }
        }
        else
        {
            Idle(hwnd);
        }

    } while (applicationRunning);

    return msg.wParam;
}

// private
bool Framework::WindowMessageLoopImpl::ProcessingMessage(WindowsHWnd hwnd) noexcept
{
    if (System::UnderlyingCastEnum<System::WindowsMessages>(msg.message) == System::WindowsMessages::Quit)
    {
        return false;
    }

    System::WindowsHAccelerator accel{ nullptr };
    if (!System::SystemTranslateAccelerator(hwnd, accel, &msg))
    {
        System::TranslateSystemMessage(&msg);
        System::DispatchSystemMessage(&msg);
    }

    return true;
}

// private
void Framework::WindowMessageLoopImpl::Idle(WindowsHWnd hwnd)
{
    FRAMEWORK_ASSERTION_0(function != nullptr, "空闲函数指针为空！");

    if (function != nullptr)
    {
        const auto timeDelta = lastTime.GetThisElapsedMillisecondTime();

        function(hwnd, timeDelta);
    }
}
