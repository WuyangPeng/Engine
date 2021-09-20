///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/09 11:16)

#include "WindowsNamedPipeTesting.h"
#include "System/Console/Using/ConsoleScreenBufferUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsNamedPipe.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsNamedPipeTesting::WindowsNamedPipeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsNamedPipeTesting)

void System::WindowsNamedPipeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsNamedPipeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePipeTest);
}

void System::WindowsNamedPipeTesting::CreatePipeTest()
{
    WindowSecurityAttributes saAttr{};
    saAttr.nLength = sizeof(WindowSecurityAttributes);
    saAttr.bInheritHandle = g_True;
    saAttr.lpSecurityDescriptor = nullptr;

    WindowsHandle hReadPipe{ nullptr };
    WindowsHandle hWritePipe{ nullptr };

    ASSERT_TRUE(CreateSystemPipe(&hReadPipe, &hWritePipe, &saAttr, 0));

    ASSERT_TRUE(CloseSystemPipe(hReadPipe));
    ASSERT_TRUE(CloseSystemPipe(hWritePipe));
}
