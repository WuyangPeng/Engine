///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 23:09)

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

namespace Framework
{
    using TestingType = WindowCreateHandle;
}

Framework::WindowCreateHandleTesting::WindowCreateHandleTesting(const OStreamShared& stream, HInstance instance, HWnd hwnd)
    : ParentType{ stream }, instance{ instance }, hwnd{ hwnd }
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
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);
    auto windowName = SYSTEM_TEXT("New Main Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };

    auto oldHwnd = WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();

    TestingType create{ instanceParameter, createParameter, size };
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(create.GetHwnd(), "创建窗口失败！");

    create.SetMainWindow();

    ASSERT_EQUAL(WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd(), create.GetHwnd());

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(oldHwnd);
}
