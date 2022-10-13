///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:00)

#include "WindowMessageTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowMessage<MiddleLayerInterface>;
}

Framework::WindowMessageTesting::WindowMessageTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageTesting)

void Framework::WindowMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloseMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMainWindowTest);
}

void Framework::WindowMessageTesting::MessageTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta, environmentDirectory };
    ASSERT_EQUAL(message.GetDelta(), delta);

    ASSERT_TRUE(message.PreCreate());
    ASSERT_TRUE(message.Initialize());
    message.PreIdle();
    message.Terminate();

    ASSERT_EQUAL(message.CreateMessage(hwnd, 0, 0), 0);

    ASSERT_EQUAL(hwnd, message.GetHwnd());

    ASSERT_EQUAL(message.SizeMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MoveMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.CharMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyDownMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyUpMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonDownMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonUpMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonDownMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonUpMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonDownMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonUpMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseMoveMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseWheelMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.PaintMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.EraseBackgroundMessage(hwnd, 0, 0), 1);

    message.Display(hwnd, 0);

    ASSERT_EQUAL(message.GetTerminateKey(), WindowApplicationTrait::KeyIdentifiers::keyTerminate);
}

void Framework::WindowMessageTesting::CloseMessageTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta, environmentDirectory };

    auto instance = System::GetHInstance();

    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    auto windowName = SYSTEM_TEXT("Test Close Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}

void Framework::WindowMessageTesting::DestroyMessageTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta, environmentDirectory };

    auto instance = System::GetHInstance();

    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    auto windowName = SYSTEM_TEXT("Test Destroy Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
    ASSERT_EQUAL(message.DestroyMessage(create.GetHwnd(), 0, 0), 0);
}

void Framework::WindowMessageTesting::SetMainWindowTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta, environmentDirectory };

    auto instance = System::GetHInstance();

    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    auto windowName = SYSTEM_TEXT("Test Close Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);

    message.SetMainWindow(create.GetHwnd());

    ASSERT_EQUAL(create.GetHwnd(), message.GetHwnd());

    message.SetMainWindow(hwnd);

    ASSERT_EQUAL(hwnd, message.GetHwnd());

    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}
