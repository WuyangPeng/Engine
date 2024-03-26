/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:26)

#include "GetProcessHandleTesting.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetProcessHandleTesting::GetProcessHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetProcessHandleTesting)

void System::GetProcessHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetProcessHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProcessTest);
}

void System::GetProcessHandleTesting::ProcessTest()
{
    const auto windowHandle = GetCurrentProcessHandle();
    ASSERT_UNEQUAL_NULL_PTR(windowHandle);

    ASSERT_EQUAL(GetCurrentProcessHandleId(), GetProcessHandleId(windowHandle));
}
