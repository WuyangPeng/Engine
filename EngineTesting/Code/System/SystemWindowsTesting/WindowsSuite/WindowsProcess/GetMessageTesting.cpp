/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:17)

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
    std::ignore = SystemTranslateAccelerator(hWnd, accelerator, &msg);
    std::ignore = TranslateSystemMessage(&msg);
    std::ignore = DispatchSystemMessage(&msg);
}
