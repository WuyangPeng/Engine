///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:47)

#include "WindowsCreateMenuTesting.h"
#include "System/Windows/Flags/WindowsCreateFlags.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsCreateMenuTesting::WindowsCreateMenuTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hwnd)
    : ParentType{ stream, instance, hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateMenuTesting)

void System::WindowsCreateMenuTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateMenuTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MenuTest);
}

void System::WindowsCreateMenuTesting::MenuTest()
{
    const auto className = GetWindowsClassName();

    const auto systemWindow = CreateWindowTest(className);
    ASSERT_UNEQUAL_NULL_PTR(systemWindow);

    DoMenuTest(systemWindow);
}

void System::WindowsCreateMenuTesting::DoMenuTest(WindowsHWnd systemWindow)
{
    ASSERT_TRUE(RemoveMenuCloseButton(systemWindow));

    const auto menu = GetWindowSystemMenu(systemWindow);

    ASSERT_UNEQUAL_NULL_PTR(menu);

    ASSERT_TRUE(RemoveSystemMenu(menu, SystemMenuCommand::Minimize, MenuItem::ByCommand));

    ASSERT_TRUE(DestroySystemWindow(systemWindow));
}
