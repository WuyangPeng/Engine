/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:19)

#include "OutputDebugStringTesting.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OutputDebugStringTesting::OutputDebugStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::OutputDebugStringTesting::OutputCharToDebugTest() const noexcept
{
    OutputDebugStringWithChar("测试信息输出至调试窗口。\n");
}

void System::OutputDebugStringTesting::OutputWCharToDebugTest() const noexcept
{
    OutputDebugStringWithWChar(L"测试信息输出至调试窗口。\n");
}

void System::OutputDebugStringTesting::OutputTCharToDebugTest() const noexcept
{
    OutputDebugStringWithTChar(SYSTEM_TEXT("测试信息输出至调试窗口。\n"));
}
