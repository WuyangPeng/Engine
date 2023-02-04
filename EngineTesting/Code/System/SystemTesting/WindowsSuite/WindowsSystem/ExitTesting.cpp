///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 20:38)

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