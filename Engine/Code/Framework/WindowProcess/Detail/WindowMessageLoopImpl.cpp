///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:00)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoopImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMessageLoopImpl::WindowMessageLoopImpl(DisplayFunction function) noexcept
    : function{ function }, lastTime{}, msg{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoopImpl)

System::WindowsWParam Framework::WindowMessageLoopImpl::EnterMessageLoop(WindowsHWnd hWnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (function != nullptr)
    {
        return EnterNewMessageLoop(hWnd);
    }
    else
    {
        return EnterOldMessageLoop();
    }
}

System::WindowsWParam Framework::WindowMessageLoopImpl::EnterOldMessageLoop() noexcept
{
    while (System::GetSystemMessage(&msg))
    {
        System::TranslateSystemMessage(&msg);
        System::DispatchSystemMessage(&msg);
    }

    return msg.wParam;
}

System::WindowsWParam Framework::WindowMessageLoopImpl::EnterNewMessageLoop(WindowsHWnd hWnd)
{
    // 启动消息循环。
    auto applicationRunning = true;

    do
    {
        if (System::PeekSystemMessage(&msg))
        {
            if (!ProcessingMessage(hWnd))
            {
                applicationRunning = false;
                continue;
            }
        }
        else
        {
            Idle(hWnd);
        }

    } while (applicationRunning);

    return msg.wParam;
}

bool Framework::WindowMessageLoopImpl::ProcessingMessage(WindowsHWnd hWnd)
{
    if (System::UnderlyingCastEnum<System::WindowsMessages>(boost::numeric_cast<int>(msg.message)) == System::WindowsMessages::Quit)
    {
        return false;
    }

    if (System::WindowsHAccelerator accelerator{ nullptr };
        !System::SystemTranslateAccelerator(hWnd, accelerator, &msg))
    {
        System::TranslateSystemMessage(&msg);
        System::DispatchSystemMessage(&msg);
    }

    return true;
}

void Framework::WindowMessageLoopImpl::Idle(WindowsHWnd hWnd) noexcept
{
    if (function != nullptr)
    {
        const auto timeDelta = lastTime.GetThisElapsedMillisecondTime();

        function(hWnd, timeDelta);
    }
}
