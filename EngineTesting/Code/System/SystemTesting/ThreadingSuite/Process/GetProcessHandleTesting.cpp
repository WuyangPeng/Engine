///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 16:57)

#include "GetProcessHandleTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::GetProcessHandleTesting ::GetProcessHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    auto windowHandle = GetCurrentProcessHandle();
    ASSERT_UNEQUAL_NULL_PTR(windowHandle);

    ASSERT_EQUAL(GetCurrentProcessHandleID(), GetProcessHandleID(windowHandle));
}
