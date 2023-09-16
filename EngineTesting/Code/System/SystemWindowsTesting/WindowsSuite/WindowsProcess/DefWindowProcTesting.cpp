///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:23)

#include "DefWindowProcTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DefWindowProcTesting::DefWindowProcTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DefWindowProcTesting)

void System::DefWindowProcTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DefWindowProcTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefWindowProcTest);
}

void System::DefWindowProcTesting::DefWindowProcTest()
{
    ASSERT_EQUAL(DefaultSystemWindowProcess(hWnd, WindowsMessages::Paint, 0, 0), 0);
}
