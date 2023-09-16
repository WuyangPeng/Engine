///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:16)

#include "GetProcessHandleTesting.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetProcessHandleTesting::GetProcessHandleTesting(const OStreamShared& stream)
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
    const auto windowHandle = GetCurrentProcessHandle();
    ASSERT_UNEQUAL_NULL_PTR(windowHandle);

    ASSERT_EQUAL(GetCurrentProcessHandleId(), GetProcessHandleId(windowHandle));
}
