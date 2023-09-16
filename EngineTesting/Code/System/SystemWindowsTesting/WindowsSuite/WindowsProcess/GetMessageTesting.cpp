///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:22)

#include "GetMessageTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetMessageTesting::GetMessageTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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
    ASSERT_TRUE(PostSystemMessage(hWnd, WindowsMessages::User, 0, 0));

    WindowsMessage msg{};
    ASSERT_TRUE(GetSystemMessage(&msg, hWnd));

    ASSERT_EQUAL(msg.hwnd, hWnd);

    WindowsHAccelerator accelerator{ nullptr };
    MAYBE_UNUSED const auto result0 = SystemTranslateAccelerator(hWnd, accelerator, &msg);
    MAYBE_UNUSED const auto result1 = TranslateSystemMessage(&msg);
    MAYBE_UNUSED const auto result2 = DispatchSystemMessage(&msg);
}
