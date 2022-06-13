///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/16 14:43)

#include "GetMessageTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetMessageTesting::GetMessageTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetMessageTesting)

void System::GetMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetMessageTest);
}

void System::GetMessageTesting::GetMessageTest()
{
    ASSERT_TRUE(PostSystemMessage(hwnd, WindowsMessages::User, 0, 0));

    WindowsMsg msg{};
    ASSERT_TRUE(GetSystemMessage(&msg, hwnd));

    ASSERT_EQUAL(msg.hwnd, hwnd);

    WindowsHAccel accel{ 0 };
    auto result = SystemTranslateAccelerator(hwnd, accel, &msg);
    result = TranslateSystemMessage(&msg);
    result = DispatchSystemMessage(&msg);
}
