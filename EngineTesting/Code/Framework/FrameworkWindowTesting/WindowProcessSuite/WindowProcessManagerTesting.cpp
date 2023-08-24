///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:46)

#include "WindowProcessManagerTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowCreate/WindowCreateHandle.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

Framework::WindowProcessManagerTesting::WindowProcessManagerTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowProcessManagerTesting)

void Framework::WindowProcessManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowProcessManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClassNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetMainWindow);
}

void Framework::WindowProcessManagerTesting::ManagerTest()
{
    ASSERT_UNEQUAL_NULL_PTR(WINDOW_PROCESS_MANAGER_SINGLETON.GetProcess());
    ASSERT_UNEQUAL_NULL_PTR(WINDOW_PROCESS_MANAGER_SINGLETON.GetFunction());

    const auto windowMessage0 = const_pointer_cast<WindowMessageInterface>(WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface());

    ASSERT_UNEQUAL_NULL_PTR(windowMessage0);

    WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage(windowMessage0);
    WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(windowMessage0);

    const auto windowMessage1 = WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface();

    ASSERT_EQUAL(windowMessage0, windowMessage1);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate());
    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.Initialize());

    WINDOW_PROCESS_MANAGER_SINGLETON.PreIdle();
    WINDOW_PROCESS_MANAGER_SINGLETON.Terminate();
}

void Framework::WindowProcessManagerTesting::ClassNameTest()
{
    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className));

    const auto newClassName = SYSTEM_TEXT("New Class"s);

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(newClassName));

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(newClassName));
}

void Framework::WindowProcessManagerTesting::SetMainWindow()
{
    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    const auto instance = System::GetHInstance();
    const auto windowName = SYSTEM_TEXT("Not Displayed Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHWnd(), hWnd);

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHWnd(create.GetHWnd());
    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHWnd(), create.GetHWnd());

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHWnd(hWnd);

    constexpr auto delta = System::gMicroseconds / 60;
    WindowMessageInterface message{ delta };

    ASSERT_EQUAL(message.CreateMessage(create.GetHWnd(), 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHWnd(), 0, 0), 0);
}
