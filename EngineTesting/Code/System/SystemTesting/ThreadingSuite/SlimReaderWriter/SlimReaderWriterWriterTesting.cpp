///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 16:10)

#include "SlimReaderWriterWriterTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterWriterTesting::SlimReaderWriterWriterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    SlimReaderWriterLock slimReaderWriterLock{};
    InitializeSlimReaderWriterLock(&slimReaderWriterLock);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, slimReaderWriterLock);

    AcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateTryThread, slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);

    ASSERT_NOT_THROW_EXCEPTION_1(TryWriterThreadSuccess, slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::WriterThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockExclusive(&slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::TryReaderThreadFailure(SlimReaderWriterLock& slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));
}

void System::SlimReaderWriterWriterTesting::TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock));
}

void System::SlimReaderWriterWriterTesting::TryWriterThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock)
{
    ASSERT_TRUE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));

    ReleaseSlimReaderWriterLockExclusive(&slimReaderWriterLock);
}

void System::SlimReaderWriterWriterTesting::CreateThread(SlimReaderWriterLock& slimReaderWriterLock)
{
    boost::thread_group threadGroup0{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup0.create_thread(boost::bind(&ClassType::ReaderThread, this, boost::ref(slimReaderWriterLock)));
        threadGroup0.create_thread(boost::bind(&ClassType::WriterThread, this, boost::ref(slimReaderWriterLock)));
    }

    threadGroup0.join_all();
}

void System::SlimReaderWriterWriterTesting::CreateTryThread(SlimReaderWriterLock& slimReaderWriterLock)
{
    boost::thread_group threadGroup1{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup1.create_thread(boost::bind(&ClassType::TryReaderThreadFailure, this, boost::ref(slimReaderWriterLock)));
        threadGroup1.create_thread(boost::bind(&ClassType::TryWriterThreadFailure, this, boost::ref(slimReaderWriterLock)));
    }

    threadGroup1.join_all();
}
