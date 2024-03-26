/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:21)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::DebugBreakTesting::DebugBreakTest() const noexcept
{
#ifdef SYSTEM_TEST_DEBUG_BREAK

    DebugBreak();

#endif  // SYSTEM_TEST_DEBUG_BREAK
}