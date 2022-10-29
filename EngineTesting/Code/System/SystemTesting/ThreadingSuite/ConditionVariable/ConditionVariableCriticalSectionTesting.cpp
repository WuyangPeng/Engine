///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:18)

#include "ConditionVariableCriticalSectionTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/ConditionVariable.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConditionVariableCriticalSectionTesting::ConditionVariableCriticalSectionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      bufferNotEmpty{},
      bufferNotFull{},
      bufferLock{},
      stopRequested{ false },
      buffer{},
      queueSize{ 0 },
      queueStartOffset{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::ConditionVariableCriticalSectionTesting::Initialize()
{
    InitializeSystemConditionVariable(&bufferNotEmpty);
    InitializeSystemConditionVariable(&bufferNotFull);

    ASSERT_TRUE(InitializeSystemCriticalSection(&bufferLock));
}

void System::ConditionVariableCriticalSectionTesting::Delete() noexcept
{
    DeleteSystemCriticalSection(&bufferLock);
}

void System::ConditionVariableCriticalSectionTesting::ThreadTest()
{
    boost::thread_group threadGroup{};
    threadGroup.create_thread(boost::bind(&ClassType::ProducerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));

    GetStream() << "按继续后，线程将退出。\n";

    SystemPause();

    EnterSystemCriticalSection(&bufferLock);
    stopRequested = true;
    LeaveSystemCriticalSection(&bufferLock);

    WakeAllSystemConditionVariable(&bufferNotEmpty);
    WakeAllSystemConditionVariable(&bufferNotFull);

    threadGroup.join_all();
}

void System::ConditionVariableCriticalSectionTesting::ProducerThreadProcedure()
{
    for (;;)
    {
        EnterCriticalSection(&bufferLock);

        while (queueSize == bufferSize && !stopRequested)
        {
            // Buffer满了。
            ASSERT_TRUE(SleepConditionVariableCriticalSection(&bufferNotFull, &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite)));
        }

        if (stopRequested)
        {
            LeaveCriticalSection(&bufferLock);
            break;
        }

        const auto offset = queueSize + queueStartOffset;
        const auto index = offset % buffer.size();

        buffer.at(index) = boost::numeric_cast<int>(index);

        ++queueSize;

        LeaveCriticalSection(&bufferLock);

        WakeConditionVariable(&bufferNotEmpty);
    }
}

void System::ConditionVariableCriticalSectionTesting::ConsumerThreadProcedure()
{
    for (;;)
    {
        EnterCriticalSection(&bufferLock);

        while (queueSize == 0 && !stopRequested)
        {
            // Buffer 是空的。
            ASSERT_TRUE(SleepConditionVariableCriticalSection(&bufferNotEmpty, &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite)));
        }

        if (stopRequested && queueSize == 0)
        {
            LeaveCriticalSection(&bufferLock);
            break;
        }

        auto value = buffer.at(queueStartOffset);

        ASSERT_EQUAL(value, queueStartOffset);

        --queueSize;
        ++queueStartOffset;

        if (queueStartOffset == boost::numeric_cast<int>(buffer.size()))
        {
            queueStartOffset = 0;
        }

        LeaveCriticalSection(&bufferLock);

        WakeConditionVariable(&bufferNotFull);
    }
}
