/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:29)

#include "ConsoleModeTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleMode.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleModeTesting::ConsoleModeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleModeTesting)

System::WindowsDWord System::ConsoleModeTesting::GetCurrentMode(WindowsHandle consoleHandle)
{
    WindowsDWord mode{ 0 };
    ASSERT_TRUE(GetSystemConsoleMode(consoleHandle, &mode));

    return mode;
}
