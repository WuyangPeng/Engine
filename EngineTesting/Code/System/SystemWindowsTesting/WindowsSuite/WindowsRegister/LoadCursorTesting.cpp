/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:17)

#include "LoadCursorTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemWindowsTesting/resource.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadCursorTesting::LoadCursorTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadCursorTesting)

void System::LoadCursorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadCursorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadCursorTest);
}

void System::LoadCursorTesting::LoadCursorTest()
{
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gArrow));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gIbeam));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gWait));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gCross));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gUpArrow));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gSizeNwse));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gSizeNesw));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gSizeWe));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gSizeNs));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gSizeAll));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gNo));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gIdcHand));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gAppStarting));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, gHelp));

    ASSERT_UNEQUAL_NULL_PTR(System::LoadSystemCursor(instance, MakeIntResource(IDC_TEST_CURSOR)));
}
