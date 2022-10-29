///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 21:59)

#include "SlimReaderWriterReaderTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterReaderTesting::SlimReaderWriterReaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    constexpr auto threadCount = 12;

    SlimReaderWriterLock slimReaderWriterLock{};
    InitializeSlimReaderWriterLock(&slimReaderWriterLock);

    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ReaderThread, this, slimReaderWriterLock));
        threadGroup.create_thread(boost::bind(&ClassType::TryReaderThreadSuccess, this, slimReaderWriterLock));
        threadGroup.create_thread(boost::bind(&ClassType::TryWriterThreadFailure, this, slimReaderWriterLock));
    }

    threadGroup.join_all();

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::ReaderThread(SlimReaderWriterLock slimReaderWriterLock) noexcept
{
    AcquireSlimReaderWriterLockShared(&slimReaderWriterLock);

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::TryReaderThreadSuccess(SlimReaderWriterLock slimReaderWriterLock)
{
    ASSERT_TRUE(TryAcquireSlimReaderWriterLockShared(&slimReaderWriterLock));

    ReleaseSlimReaderWriterLockShared(&slimReaderWriterLock);
}

void System::SlimReaderWriterReaderTesting::TryWriterThreadFailure(SlimReaderWriterLock slimReaderWriterLock)
{
    ASSERT_FALSE(TryAcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock));
}
