///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:55)

#include "AdvancedWindowsDebuggingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/AdvancedWindowsDebugging/Helper/AdvancedWindowsDebuggingClassInvariantMacro.h"

BookDebugging::AdvancedWindowsDebugging::AdvancedWindowsDebuggingPlaceholderTesting::AdvancedWindowsDebuggingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ADVANCED_WINDOWS_DEBUGGING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDebugging::AdvancedWindowsDebugging, AdvancedWindowsDebuggingPlaceholderTesting)

void BookDebugging::AdvancedWindowsDebugging::AdvancedWindowsDebuggingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDebugging::AdvancedWindowsDebugging::AdvancedWindowsDebuggingPlaceholderTesting::MainTest() noexcept
{
}
