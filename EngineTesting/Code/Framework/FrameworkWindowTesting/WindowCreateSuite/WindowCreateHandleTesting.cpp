///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:51)

#include "WindowCreateHandleTesting.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

Framework::WindowCreateHandleTesting::WindowCreateHandleTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd)
    : ParentType{ stream }, instance{ instance }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowCreateHandleTesting)

void Framework::WindowCreateHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowCreateHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateTest);
}

void Framework::WindowCreateHandleTesting::CreateTest()
{
    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));
    const auto windowName = SYSTEM_TEXT("New Main Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };

    const auto oldHWnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHWnd();

    WindowCreateHandle create{ instanceParameter, createParameter, size };
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(create.GetHWnd(), "创建窗口失败！");

    create.SetMainWindow();

    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHWnd(), create.GetHWnd());

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHWnd(oldHWnd);
}
