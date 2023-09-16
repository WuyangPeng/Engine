///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:55)

#include "ConditionVariableCriticalSectionTesting.h"
#include "Data/CriticalSectionPacking.h"
#include "System/Threading/ConditionVariable.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConditionVariableCriticalSectionTesting::ConditionVariableCriticalSectionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      bufferLock{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConditionVariableCriticalSectionTesting)

void System::ConditionVariableCriticalSectionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConditionVariableCriticalSectionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Initialize);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Delete);
}

void System::ConditionVariableCriticalSectionTesting::DoInitialize()
{
    ASSERT_TRUE(InitializeSystemCriticalSection(&bufferLock));
}

void System::ConditionVariableCriticalSectionTesting::Delete() noexcept
{
    DeleteSystemCriticalSection(&bufferLock);
}

void System::ConditionVariableCriticalSectionTesting::ThreadPause()
{
    GetStream() << "按继续后，线程将退出。\n";

    SystemPause();

    EnterSystemCriticalSection(&bufferLock);
    SetStopRequested(true);
    LeaveSystemCriticalSection(&bufferLock);
    WakeAllConditionVariable();
}

bool System::ConditionVariableCriticalSectionTesting::DoProducerThreadProcedure()
{
    CriticalSectionPacking criticalSectionPacking{ bufferLock };

    while (IsFull())
    {
        ASSERT_TRUE(SleepConditionVariableCriticalSection(GetBufferNotFull(), &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite)));
    }

    if (IsStopRequested())
    {
        return true;
    }

    ASSERT_NOT_THROW_EXCEPTION_0(PushBuffer);

    ASSERT_NOT_THROW_EXCEPTION_0(WakeNotEmptyConditionVariable);

    return false;
}

bool System::ConditionVariableCriticalSectionTesting::DoConsumerThreadProcedure()
{
    CriticalSectionPacking criticalSectionPacking{ bufferLock };

    while (IsEmpty())
    {
        ASSERT_TRUE(SleepConditionVariableCriticalSection(GetBufferNotEmpty(), &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite)));
    }

    if (IsStopRequested() && GetQueueSize() == 0)
    {
        return true;
    }

    ASSERT_NOT_THROW_EXCEPTION_0(PopBuffer);

    ASSERT_NOT_THROW_EXCEPTION_0(WakeNotFullConditionVariable);

    return false;
}
