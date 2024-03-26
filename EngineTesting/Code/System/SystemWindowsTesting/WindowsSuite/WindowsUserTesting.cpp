/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:16)

#include "WindowsUserTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsUser.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsUserTesting::WindowsUserTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsUserTesting)

void System::WindowsUserTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsUserTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HWndTest);
}

void System::WindowsUserTesting::MessageTest()
{
    ASSERT_TRUE(PostSystemThreadMessage(GetCurrentThreadId(), WindowsMessages::Paint, 0, 0));
}

void System::WindowsUserTesting::HWndTest()
{
    ASSERT_TRUE(SystemInvalidateRect(hWnd));
    ASSERT_TRUE(UpdateSystemWindows(hWnd));
}
