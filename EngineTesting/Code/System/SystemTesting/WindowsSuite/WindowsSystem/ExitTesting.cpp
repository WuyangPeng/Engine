///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/08 22:42)

#include "ExitTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define SYSTEM_TEST_EXIT
#undef SYSTEM_TEST_EXIT

System::ExitTesting::ExitTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ExitTesting)

void System::ExitTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ExitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExitTest);
}

void System::ExitTesting::ExitTest() noexcept
{
#ifdef SYSTEM_TEST_EXIT
    Exit();
#endif  // SYSTEM_TEST_EXIT
}