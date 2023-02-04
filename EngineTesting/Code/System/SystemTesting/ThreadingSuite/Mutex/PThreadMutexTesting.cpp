///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 11:46)

#include "PThreadMutexTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PThreadMutexTesting::PThreadMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }, threadSum{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PThreadMutexTesting)

void System::PThreadMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PThreadMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TrylockTest);
}

void System::PThreadMutexTesting::ThreadTest()
{
    PthreadMutexattrT attribute{};
    PthreadMutexT mutex{};

    ASSERT_NOT_THROW_EXCEPTION_2(PthreadMutexInitTest, attribute, mutex);

    threadSum = 0;

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, mutex);

    ASSERT_EQUAL(threadSum, threadCount);

    ASSERT_NOT_THROW_EXCEPTION_2(PthreadMutexDestroyTest, mutex, attribute);
}

void System::PThreadMutexTesting::PthreadMutexInitTest(PthreadMutexattrT& attribute, PthreadMutexT& mutex)
{
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeInit(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeSetType(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexInit(&attribute, &mutex), PthreadResult::Successful);
}

void System::PThreadMutexTesting::CreateThread(PthreadMutexT& mutex)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, &mutex));
    }

    threadGroup.join_all();
}

void System::PThreadMutexTesting::PthreadMutexDestroyTest(PthreadMutexT& mutex, PthreadMutexattrT& attribute)
{
    ASSERT_ENUM_EQUAL(PthreadMutexDestroy(&mutex), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeDestroy(&attribute), PthreadResult::Successful);
}

void System::PThreadMutexTesting::TrylockTest()
{
    PthreadMutexattrT attribute{};
    PthreadMutexT mutex{};

    ASSERT_NOT_THROW_EXCEPTION_2(PthreadMutexInitTest, attribute, mutex);

    ASSERT_NOT_THROW_EXCEPTION_1(TrylockTimeoutThreadTest, mutex);

    ASSERT_NOT_THROW_EXCEPTION_1(TrylockSuccessThreadTest, mutex);

    ASSERT_NOT_THROW_EXCEPTION_2(PthreadMutexDestroyTest, mutex, attribute);
}

void System::PThreadMutexTesting::TrylockTimeoutThreadTest(PthreadMutexT& mutex)
{
    ASSERT_ENUM_EQUAL(PthreadMutexLock(&mutex), PthreadResult::Successful);

    boost::thread thread{ boost::bind(&ClassType::TrylockTimeoutTest, this, &mutex) };

    thread.join();

    ASSERT_ENUM_EQUAL(PthreadMutexUnlock(&mutex), PthreadResult::Successful);
}

void System::PThreadMutexTesting::TrylockSuccessThreadTest(PthreadMutexT& mutex)
{
    boost::thread thread1{ boost::bind(&ClassType::TrylockSuccessTest, this, &mutex) };

    thread1.join();
}

void System::PThreadMutexTesting::WaitForMutexTest(PthreadMutexT* mutex)
{
    ASSERT_ENUM_EQUAL(PthreadMutexLock(mutex), PthreadResult::Successful);

    const auto original = threadSum;

    for (auto i = 0; i < threadCount; ++i)
    {
        --threadSum;
    }

    threadSum = original;

    ++threadSum;

    ASSERT_ENUM_EQUAL(PthreadMutexUnlock(mutex), PthreadResult::Successful);
}

void System::PThreadMutexTesting::TrylockTimeoutTest(PthreadMutexT* mutex)
{
    ASSERT_ENUM_UNEQUAL(PthreadMutexTrylock(mutex), PthreadResult::Successful);
}

void System::PThreadMutexTesting::TrylockSuccessTest(PthreadMutexT* mutex)
{
    ASSERT_ENUM_EQUAL(PthreadMutexTrylock(mutex), PthreadResult::Successful);

    ASSERT_ENUM_EQUAL(PthreadMutexUnlock(mutex), PthreadResult::Successful);
}
