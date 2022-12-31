///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/05 0:49)

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
