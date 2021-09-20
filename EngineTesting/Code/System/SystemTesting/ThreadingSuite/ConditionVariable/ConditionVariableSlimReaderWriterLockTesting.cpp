///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/30 15:30)

#include "ConditionVariableSlimReaderWriterLockTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
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

void System::ConditionVariableSlimReaderWriterLockTesting::Initialize() noexcept
{
    InitializeSystemConditionVariable(&bufferNotEmpty);
    InitializeSystemConditionVariable(&bufferNotFull);

    InitializeSlimReaderWriterLock(&bufferLock);
}

void System::ConditionVariableSlimReaderWriterLockTesting::ThreadTest()
{
    boost::thread_group threadGroup{};
    threadGroup.create_thread(boost::bind(&ClassType::ProducerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));

    GetStream() << "���������߳̽��˳���\n";

    SystemPause();

    AcquireSlimReaderWriterLockExclusive(&bufferLock);
    stopRequested = true;
    ReleaseSlimReaderWriterLockExclusive(&bufferLock);

    WakeAllSystemConditionVariable(&bufferNotEmpty);
    WakeAllSystemConditionVariable(&bufferNotFull);

    threadGroup.join_all();
}

void System::ConditionVariableSlimReaderWriterLockTesting::ProducerThreadProcedure()
{
    for (;;)
    {
        AcquireSlimReaderWriterLockExclusive(&bufferLock);

        while (queueSize == sm_BufferSize && !stopRequested)
        {
            // Buffer���ˡ�
            ASSERT_TRUE(SleepConditionVariableSlimReaderWriter(&bufferNotFull, &bufferLock, EnumCastUnderlying<WindowsDWord>(MutexWait::Infinite), ConditionVariableLockMode::Exclusive));
        }

        if (stopRequested)
        {
            ReleaseSlimReaderWriterLockExclusive(&bufferLock);
            break;
        }

        const auto offset = queueSize + queueStartOffset;
        const auto index = offset % buffer.size();

        buffer.at(index) = boost::numeric_cast<int>(index);

        ++queueSize;

        ReleaseSlimReaderWriterLockExclusive(&bufferLock);

        WakeSystemConditionVariable(&bufferNotEmpty);
    }
}

void System::ConditionVariableSlimReaderWriterLockTesting::ConsumerThreadProcedure()
{
    for (;;)
    {
        AcquireSlimReaderWriterLockExclusive(&bufferLock);

        while (queueSize == 0 && !stopRequested)
        {
            // Buffer �ǿյġ�
            ASSERT_TRUE(SleepConditionVariableSlimReaderWriter(&bufferNotEmpty, &bufferLock, static_cast<WindowsDWord>(MutexWait::Infinite), ConditionVariableLockMode::Exclusive));
        }

        if (stopRequested && queueSize == 0)
        {
            ReleaseSlimReaderWriterLockExclusive(&bufferLock);
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

        ReleaseSlimReaderWriterLockExclusive(&bufferLock);

        WakeSystemConditionVariable(&bufferNotFull);
    }
}
