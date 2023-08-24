///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 14:53)

#include "WindowMessageTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

using namespace std::literals;

Framework::WindowMessageTesting::WindowMessageTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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
    constexpr auto delta = System::gMicroseconds / 60;
    WindowMessage<MiddleLayerInterface> message{ delta, environmentDirectory };
    ASSERT_EQUAL(message.GetDelta(), delta);

    ASSERT_TRUE(message.PreCreate());
    ASSERT_TRUE(message.Initialize());
    message.PreIdle();
    message.Terminate();

    ASSERT_EQUAL(message.CreateMessage(hWnd, 0, 0), 0);

    ASSERT_EQUAL(hWnd, message.GetHWnd());

    ASSERT_EQUAL(message.SizeMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.MoveMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.CharMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyDownMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyUpMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonDownMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonUpMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonDownMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonUpMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonDownMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonUpMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseMoveMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseWheelMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.PaintMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.EraseBackgroundMessage(hWnd, 0, 0), 1);

    message.Display(hWnd, 0);

    ASSERT_EQUAL(message.GetTerminateKey(), WindowApplicationTrait::KeyIdentifiers::keyTerminate);
}

void Framework::WindowMessageTesting::CloseMessageTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::gMicroseconds / 60;
    WindowMessage<MiddleLayerInterface> message{ delta, environmentDirectory };

    const auto instance = System::GetHInstance();

    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    const auto windowName = SYSTEM_TEXT("Test Close Message Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHWnd(), 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHWnd(), 0, 0), 0);
}

void Framework::WindowMessageTesting::DestroyMessageTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::gMicroseconds / 60;
    WindowMessage<MiddleLayerInterface> message{ delta, environmentDirectory };

    const auto instance = System::GetHInstance();

    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    const auto windowName = SYSTEM_TEXT("Test Destroy Message Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(hWnd, 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHWnd(), 0, 0), 0);
    ASSERT_EQUAL(message.DestroyMessage(create.GetHWnd(), 0, 0), 0);
}

void Framework::WindowMessageTesting::SetMainWindowTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    constexpr auto delta = System::gMicroseconds / 60;
    WindowMessage<MiddleLayerInterface> message{ delta, environmentDirectory };

    const auto instance = System::GetHInstance();

    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    const auto windowName = SYSTEM_TEXT("Test Close Message Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHWnd(), 0, 0), 0);

    message.SetMainWindow(create.GetHWnd());

    ASSERT_EQUAL(create.GetHWnd(), message.GetHWnd());

    message.SetMainWindow(hWnd);

    ASSERT_EQUAL(hWnd, message.GetHWnd());

    ASSERT_EQUAL(message.CloseMessage(create.GetHWnd(), 0, 0), 0);
}
