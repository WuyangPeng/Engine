///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 10:56)

#include "MessageBoxTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MessageBoxTesting::MessageBoxTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MessageBoxTesting)

void System::MessageBoxTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MessageBoxTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MessageBoxTest);
}

void System::MessageBoxTesting::MessageBoxTest()
{
    MAYBE_UNUSED const auto result = MessageBox(hwnd, SYSTEM_TEXT("��Ϣ"), SYSTEM_TEXT("��Ϣ����"));
}
