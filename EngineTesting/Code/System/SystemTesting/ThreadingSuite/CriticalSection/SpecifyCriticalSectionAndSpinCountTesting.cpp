///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:56)

#include "SpecifyCriticalSectionAndSpinCountTesting.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/CriticalSectionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SpecifyCriticalSectionAndSpinCountTesting::SpecifyCriticalSectionAndSpinCountTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SpecifyCriticalSectionAndSpinCountTesting)

void System::SpecifyCriticalSectionAndSpinCountTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SpecifyCriticalSectionAndSpinCountTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CriticalSectionTest);
}

void System::SpecifyCriticalSectionAndSpinCountTesting::CriticalSectionTest()
{
    constexpr WindowsDWord spinCount{ 4000 };
    constexpr WindowsDWord setSpinCount{ 4096 };

    ThreadingCriticalSection criticalSection{};

    ASSERT_TRUE(InitializeSystemCriticalSectionAndSpinCount(&criticalSection, spinCount));

    const auto count = SetSystemCriticalSectionSpinCount(&criticalSection, setSpinCount);
    ASSERT_EQUAL(count, spinCount);

    ASSERT_NOT_THROW_EXCEPTION_1(EnterCriticalSectionTest, criticalSection);

    DeleteSystemCriticalSection(&criticalSection);
}

void System::SpecifyCriticalSectionAndSpinCountTesting::EnterCriticalSectionTest(ThreadingCriticalSection& criticalSection)
{
    EnterSystemCriticalSection(&criticalSection);

    ASSERT_TRUE(TryEnterSystemCriticalSection(&criticalSection));
    LeaveSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);
}
