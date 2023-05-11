///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 19:46)

#include "GetActiveWindowTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetActiveWindowTesting::GetActiveWindowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetActiveWindowTesting)

void System::GetActiveWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetActiveWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetActiveWindowTest);
}

void System::GetActiveWindowTesting::GetActiveWindowTest() noexcept
{
    MAYBE_UNUSED const auto* activeWindow = GetActiveWindow();
}