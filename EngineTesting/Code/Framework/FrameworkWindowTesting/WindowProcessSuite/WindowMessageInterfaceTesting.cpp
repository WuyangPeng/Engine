// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 13:56)

#include "WindowMessageInterfaceTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowMessageInterface.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowMessageInterface;
}

Framework::WindowMessageInterfaceTesting::WindowMessageInterfaceTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, m_Hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageInterfaceTesting)

void Framework::WindowMessageInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMessageInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloseMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMainWindowTest);
}

void Framework::WindowMessageInterfaceTesting::MessageTest()
{
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta };
    ASSERT_EQUAL(message.GetDelta(), delta);

    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };

    ASSERT_TRUE(message.PreCreate(environmentDirectory));
    ASSERT_TRUE(message.Initialize());
    message.PreIdle();
    message.Terminate();

    ASSERT_EQUAL(message.CreateMessage(m_Hwnd, 0, 0), 0);

    ASSERT_EQUAL(m_Hwnd, message.GetHwnd());

    ASSERT_EQUAL(message.SizeMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MoveMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.CharMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyDownMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.KeyUpMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonDownMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.LeftButtonUpMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonDownMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MiddleButtonUpMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonDownMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.RightButtonUpMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseMoveMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.MouseWheelMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.PaintMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.EraseBackgroundMessage(m_Hwnd, 0, 0), 1);

    message.Display(m_Hwnd, 0);

    ASSERT_EQUAL(message.GetTerminateKey(), WindowApplicationTrait::KeyIdentifiers::keyTerminate);
}

void Framework::WindowMessageInterfaceTesting::CloseMessageTest()
{
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta };

    auto instance = System::GetHInstance();

    System::String className{};
    [[maybe_unused]] const auto value = System::GetSystemClassName(m_Hwnd, className);

    auto windowName = SYSTEM_TEXT("Not Displayed Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}

void Framework::WindowMessageInterfaceTesting::DestroyMessageTest()
{
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta };

    auto instance = System::GetHInstance();

    System::String className{};
    [[maybe_unused]] const auto value = System::GetSystemClassName(m_Hwnd, className);

    auto windowName = SYSTEM_TEXT("Test Destroy Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(m_Hwnd, 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
    ASSERT_EQUAL(message.DestroyMessage(create.GetHwnd(), 0, 0), 0);
}

void Framework::WindowMessageInterfaceTesting::SetMainWindowTest()
{
    constexpr auto delta = System::g_Microseconds / 60;
    TestingType message{ delta };

    auto instance = System::GetHInstance();

    System::String className{};
    [[maybe_unused]] const auto value = System::GetSystemClassName(m_Hwnd, className);

    auto windowName = SYSTEM_TEXT("Not Displayed Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);

    message.SetMainWindow(create.GetHwnd());

    ASSERT_EQUAL(create.GetHwnd(), message.GetHwnd());

    message.SetMainWindow(m_Hwnd);

    ASSERT_EQUAL(m_Hwnd, message.GetHwnd());

    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}