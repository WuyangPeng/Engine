///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:44)

#include "SpecifyCriticalSectionTesting.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/CriticalSectionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SpecifyCriticalSectionTesting::SpecifyCriticalSectionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SpecifyCriticalSectionTesting)

void System::SpecifyCriticalSectionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SpecifyCriticalSectionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SpecifyCriticalSectionTest);
}

void System::SpecifyCriticalSectionTesting::SpecifyCriticalSectionTest()
{
    ThreadingCriticalSection criticalSection{};

    ASSERT_TRUE(InitializeSystemCriticalSection(&criticalSection, 0, CriticalSectionInfo::Default));

    EnterSystemCriticalSection(&criticalSection);

    ASSERT_TRUE(TryEnterSystemCriticalSection(&criticalSection));
    LeaveSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);

    DeleteSystemCriticalSection(&criticalSection);
}
