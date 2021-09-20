///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 11:08)

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

    EnterSystemCriticalSection(&criticalSection);

    ASSERT_TRUE(TryEnterSystemCriticalSection(&criticalSection));
    LeaveSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);

    DeleteSystemCriticalSection(&criticalSection);
}
