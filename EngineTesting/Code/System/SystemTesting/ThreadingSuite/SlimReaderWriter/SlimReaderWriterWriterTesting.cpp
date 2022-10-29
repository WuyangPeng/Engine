///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 22:00)

#include "SlimReaderWriterWriterTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterWriterTesting::SlimReaderWriterWriterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SlimReaderWriterWriterTesting)

void System::SlimReaderWriterWriterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SlimReaderWriterWriterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::SlimReaderWriterWriterTesting::ThreadTest()
{
    constexpr auto threadCount = 12;

    SlimReaderWriterLock slimReaderWriterLock{};
    InitializeSlimReaderWriterLock(&slimReaderWriterLock);

    boost::thread_group threadGroup0{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup0.create_thread(boost::bind(&ClassType::ReaderThread, this, slimReaderWriterLock));
        threadGroup0.create_thread(boost::bind(&ClassType::WriterThread, this, slimReaderWriterLock));
    }

    threadGroup0.join_all();

    AcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock);

    boost::thread_group threadGroup1{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup1.create_thread(boost::bind(&ClassType::TryReaderThreadFailure, this, slimReaderWriterLock));
        threadGroup1.create_thread(boost::bind(&ClassType::TryWriterThreadFailure, this, slimReaderWriterLock));
    }

    threadGroup1.join_all();

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);

    TryWriterThreadSuccess(slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::ReaderThread(SlimReaderWriterLock slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::WriterThread(SlimReaderWriterLock slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockExclusive(&slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::TryReaderThreadFailure(SlimReaderWriterLock slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));
}

void System::SlimReaderWriterWriterTesting::TryWriterThreadFailure(SlimReaderWriterLock slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock));
}

void System::SlimReaderWriterWriterTesting::TryWriterThreadSuccess(SlimReaderWriterLock slimReaderWriterLock)
{
    ASSERT_TRUE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));

    ReleaseSlimReaderWriterLockExclusive(&slimReaderWriterLock);
}
