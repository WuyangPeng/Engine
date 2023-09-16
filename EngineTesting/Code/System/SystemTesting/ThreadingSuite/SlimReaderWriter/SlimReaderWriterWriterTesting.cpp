///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:22)

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
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, &slimReaderWriterLock]() noexcept {
            this->ReaderThread(slimReaderWriterLock);
        });

        threadGroup.create_thread([this, &slimReaderWriterLock]() noexcept {
            this->WriterThread(slimReaderWriterLock);
        });
    }

    threadGroup.join_all();
}

void System::SlimReaderWriterWriterTesting::CreateTryThread(SlimReaderWriterLock& slimReaderWriterLock)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, &slimReaderWriterLock]() {
            this->TryReaderThreadFailure(slimReaderWriterLock);
        });

        threadGroup.create_thread([this, &slimReaderWriterLock]() {
            this->TryWriterThreadFailure(slimReaderWriterLock);
        });
    }

    threadGroup.join_all();
}
