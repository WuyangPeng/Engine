///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:31)

#include "WaitableTimerTestingBase.h"
#include "System/Threading/WaitableTimer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitableTimerTestingBase::WaitableTimerTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitableTimerTestingBase)

void System::WaitableTimerTestingBase::CloseWaitableTimerTest(WindowsHandle waitableTimerHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseSystemWaitableTimer(waitableTimerHandle));
}
