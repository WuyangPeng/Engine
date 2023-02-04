///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 0:02)

#include "OutputDebugStringTesting.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OutputDebugStringTesting::OutputDebugStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OutputDebugStringTesting)

void System::OutputDebugStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OutputDebugStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OutputCharToDebugTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputWCharToDebugTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputTCharToDebugTest);
}

void System::OutputDebugStringTesting::OutputCharToDebugTest() noexcept
{
    OutputDebugStringWithChar("测试信息输出至调试窗口。\n");
}

void System::OutputDebugStringTesting::OutputWCharToDebugTest() noexcept
{
    OutputDebugStringWithWChar(L"测试信息输出至调试窗口。\n");
}

void System::OutputDebugStringTesting::OutputTCharToDebugTest() noexcept
{
    OutputDebugStringWithTChar(SYSTEM_TEXT("测试信息输出至调试窗口。\n"));
}
