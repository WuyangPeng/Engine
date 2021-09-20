///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/07 10:56)

#include "SendMessageTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SendMessageTesting::SendMessageTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SendMessageTesting)

void System::SendMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SendMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendMessageTest);
}

void System::SendMessageTesting::SendMessageTest() noexcept
{
    MAYBE_UNUSED const auto result = SendSystemMessage(hwnd, WindowsMessages::User, 0, 0);
}
