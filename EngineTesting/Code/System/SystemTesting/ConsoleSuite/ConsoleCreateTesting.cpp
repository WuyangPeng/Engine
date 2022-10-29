///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 22:00)

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
    auto windowHWnd = GetSystemConsoleWindow();

    ASSERT_TRUE(IsHandleValid(windowHWnd));
}
