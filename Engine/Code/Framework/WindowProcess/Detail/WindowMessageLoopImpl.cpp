///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:08)

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
    // ������Ϣѭ����
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
    FRAMEWORK_ASSERTION_0(function != nullptr, "���к���ָ��Ϊ�գ�");

    if (function != nullptr)
    {
        const auto timeDelta = lastTime.GetThisElapsedMillisecondTime();

        function(hwnd, timeDelta);
    }
}
