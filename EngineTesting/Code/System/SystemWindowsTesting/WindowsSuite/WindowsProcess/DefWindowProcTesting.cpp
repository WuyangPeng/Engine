///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:06)

#include "DefWindowProcTesting.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DefWindowProcTesting::DefWindowProcTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    ASSERT_EQUAL(DefaultSystemWindowProcess(hwnd, WindowsMessages::Paint, 0, 0), 0);
}
