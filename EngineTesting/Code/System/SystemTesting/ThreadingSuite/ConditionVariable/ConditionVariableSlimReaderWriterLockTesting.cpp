/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:31)

#include "ConditionVariableSlimReaderWriterLockTesting.h"
#include "Data/SlimReaderWriterPacking.h"
#include "System/Threading/ConditionVariable.h"
#include "System/Threading/Flags/ConditionVariableFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/SlimReaderWriter.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConditionVariableSlimReaderWriterLockTesting::ConditionVariableSlimReaderWriterLockTesting(const OStreamShared& stream)
    : ParentType{ stream },
      bufferLock{}
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConditionVariableSlimReaderWriterLockTesting)

void System::ConditionVariableSlimReaderWriterLockTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConditionVariableSlimReaderWriterLockTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Initialize);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::ConditionVariableSlimReaderWriterLockTesting::DoInitialize() noexcept
{
    InitializeSlimReaderWriterLock(&bufferLock);
}

void System::ConditionVariableSlimReaderWriterLockTesting::ThreadPause()
{
    GetStream() << "按继续后，线程将退出。\n";

    SystemPause();

    AcquireSlimReaderWriterLockExclusive(&bufferLock);
    SetStopRequested(true);
    ReleaseSlimReaderWriterLockExclusive(&bufferLock);

    WakeAllConditionVariable();
}

bool System::ConditionVariableSlimReaderWriterLockTesting::DoProducerThreadProcedure()
{
    SlimReaderWriterPacking slimReaderWriterPacking{ bufferLock };

    while (IsFull())
    {
        ASSERT_TRUE(SleepConditionVariableSlimReaderWriter(GetBufferNotFull(), &bufferLock, EnumCastUnderlying<WindowsDWord>(MutexWait::Infinite), ConditionVariableLockMode::Exclusive));
    }

    if (IsStopRequested())
    {
        return true;
    }

    ASSERT_NOT_THROW_EXCEPTION_0(PushBuffer);

    ASSERT_NOT_THROW_EXCEPTION_0(WakeNotEmptyConditionVariable);

    return false;
}

bool System::ConditionVariableSlimReaderWriterLockTesting::DoConsumerThreadProcedure()
{
    SlimReaderWriterPacking slimReaderWriterPacking{ bufferLock };

    while (IsEmpty())
    {
        ASSERT_TRUE(SleepConditionVariableSlimReaderWriter(GetBufferNotEmpty(), &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite), ConditionVariableLockMode::Exclusive));
    }

    if (IsStopRequested() && GetQueueSize() == 0)
    {
        return true;
    }

    ASSERT_NOT_THROW_EXCEPTION_0(PopBuffer);

    ASSERT_NOT_THROW_EXCEPTION_0(WakeNotFullConditionVariable);

    return false;
}
