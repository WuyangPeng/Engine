/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:16)

#include "WindowsCreateMenuTesting.h"
#include "System/Windows/Flags/WindowsCreateFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsCreateMenuTesting::WindowsCreateMenuTesting(const OStreamShared& stream, WindowsHInstance instance, WindowsHWnd hWnd)
    : ParentType{ stream, instance, hWnd }
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
