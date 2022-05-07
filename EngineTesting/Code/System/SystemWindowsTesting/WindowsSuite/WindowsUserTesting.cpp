///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/09 15:52)

#include "WindowsUserTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsUser.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsUserTesting::WindowsUserTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    ASSERT_NOT_THROW_EXCEPTION_0(HwndTest);
}

void System::WindowsUserTesting::MessageTest()
{
    ASSERT_TRUE(PostSystemThreadMessage(GetCurrentThreadId(), WindowsMessages::Paint, 0, 0));
}

void System::WindowsUserTesting::HwndTest()
{
    ASSERT_TRUE(SystemInvalidateRect(hwnd));
    ASSERT_TRUE(UpdateSystemWindows(hwnd));
}