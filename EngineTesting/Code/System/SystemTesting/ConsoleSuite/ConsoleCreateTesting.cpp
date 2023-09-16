///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:41)

#include "ConsoleCreateTesting.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Console/ConsoleHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCreateTesting::ConsoleCreateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleCreateTesting)

void System::ConsoleCreateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleCreateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSystemConsoleWindowTest);

    // ConsoleCreate的单元测试使用ConsoleSystemTesting进行。
}

void System::ConsoleCreateTesting::GetSystemConsoleWindowTest()
{
    const auto windowHWnd = GetSystemConsoleWindow();

    ASSERT_TRUE(IsHandleValid(windowHWnd));
}
