///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 16:18)

#include "DebugBreakTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define SYSTEM_TEST_DEBUG_BREAK
#undef SYSTEM_TEST_DEBUG_BREAK

System::DebugBreakTesting::DebugBreakTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DebugBreakTesting)

void System::DebugBreakTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DebugBreakTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DebugBreakTest);
}

void System::DebugBreakTesting::DebugBreakTest() noexcept
{
#ifdef SYSTEM_TEST_DEBUG_BREAK

    DebugBreak();

#endif  // SYSTEM_TEST_DEBUG_BREAK
}