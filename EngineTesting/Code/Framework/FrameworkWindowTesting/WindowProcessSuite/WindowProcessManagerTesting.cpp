///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 13:59)

#include "WindowProcessManagerTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowCreate/WindowCreateHandle.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using std::const_pointer_cast;
using namespace std::literals;

Framework::WindowProcessManagerTesting::WindowProcessManagerTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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

    auto windowMessage1 = const_pointer_cast<WindowMessageInterface>(WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface());

    ASSERT_UNEQUAL_NULL_PTR(windowMessage1);

    WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage(windowMessage1);
    WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(windowMessage1);

    auto windowMessage2 = WINDOW_PROCESS_MANAGER_SINGLETON.GetWindowMessageInterface();

    ASSERT_EQUAL(windowMessage1, windowMessage2);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate());
    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.Initialize());

    WINDOW_PROCESS_MANAGER_SINGLETON.PreIdle();
    WINDOW_PROCESS_MANAGER_SINGLETON.Terminate();
}

void Framework::WindowProcessManagerTesting::ClassNameTest()
{
    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className));

    System::String newClassName{ SYSTEM_TEXT("New Class"s) };

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(newClassName));

    ASSERT_TRUE(WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(newClassName));
}

void Framework::WindowProcessManagerTesting::SetMainWindow()
{
    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    auto instance = System::GetHInstance();
    auto windowName = SYSTEM_TEXT("Not Displayed Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), hwnd);

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(create.GetHwnd());
    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), create.GetHwnd());

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(hwnd);

    constexpr auto delta = System::g_Microseconds / 60;
    WindowMessageInterface message{ delta };

    ASSERT_EQUAL(message.CreateMessage(create.GetHwnd(), 0, 0), 0);
    ASSERT_EQUAL(message.CloseMessage(create.GetHwnd(), 0, 0), 0);
}
