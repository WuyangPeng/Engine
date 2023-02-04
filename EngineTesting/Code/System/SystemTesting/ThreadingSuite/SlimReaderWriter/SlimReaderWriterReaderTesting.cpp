///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 16:08)

#include "SlimReaderWriterReaderTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterReaderTesting::SlimReaderWriterReaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SlimReaderWriterReaderTesting)

void System::SlimReaderWriterReaderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SlimReaderWriterReaderTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::SlimReaderWriterReaderTesting::ThreadTest()
{
    SlimReaderWriterLock slimReaderWriterLock{};
    InitializeSlimReaderWriterLock(&slimReaderWriterLock);

    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::TryReaderThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock)
{
    ASSERT_TRUE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock));
}

void System::SlimReaderWriterReaderTesting::CreateThread(SlimReaderWriterLock& slimReaderWriterLock)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ReaderThread, this, boost::ref(slimReaderWriterLock)));
        threadGroup.create_thread(boost::bind(&ClassType::TryReaderThreadSuccess, this, boost::ref(slimReaderWriterLock)));
        threadGroup.create_thread(boost::bind(&ClassType::TryWriterThreadFailure, this, boost::ref(slimReaderWriterLock)));
    }

    threadGroup.join_all();
}
