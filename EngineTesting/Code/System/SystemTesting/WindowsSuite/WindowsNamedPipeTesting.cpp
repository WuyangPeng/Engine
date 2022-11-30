///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 19:05)

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
    saAttr.bInheritHandle = gTrue;
    saAttr.lpSecurityDescriptor = nullptr;

    WindowsHandle hReadPipe{ nullptr };
    WindowsHandle hWritePipe{ nullptr };

    ASSERT_TRUE(CreateSystemPipe(&hReadPipe, &hWritePipe, &saAttr, 0));

    ASSERT_TRUE(CloseSystemPipe(hReadPipe));
    ASSERT_TRUE(CloseSystemPipe(hWritePipe));
}
