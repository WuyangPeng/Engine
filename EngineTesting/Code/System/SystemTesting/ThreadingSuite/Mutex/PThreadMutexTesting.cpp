/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:29)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PThreadMutexTesting)

void System::PThreadMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PThreadMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockTest);
}

void System::PThreadMutexTesting::ThreadTest()
{
    PThreadMutexAttrT attribute{};
    PThreadMutexT mutex{};

    ASSERT_NOT_THROW_EXCEPTION_2(PThreadMutexInitTest, attribute, mutex);

    threadSum = 0;

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, mutex);

    ASSERT_EQUAL(threadSum, threadCount);

    ASSERT_NOT_THROW_EXCEPTION_2(PThreadMutexDestroyTest, mutex, attribute);
}

void System::PThreadMutexTesting::PThreadMutexInitTest(PThreadMutexAttrT& attribute, PThreadMutexT& mutex)
{
    ASSERT_EQUAL(PThreadMutexAttributeInit(&attribute), PThreadResult::Successful);
    ASSERT_EQUAL(PThreadMutexAttributeSetType(&attribute), PThreadResult::Successful);
    ASSERT_EQUAL(PThreadMutexInit(&attribute, &mutex), PThreadResult::Successful);
}

void System::PThreadMutexTesting::CreateThread(PThreadMutexT& mutex)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, &mutex]() {
            this->WaitForMutexTest(&mutex);
        });
    }

    threadGroup.join_all();
}

void System::PThreadMutexTesting::PThreadMutexDestroyTest(PThreadMutexT& mutex, PThreadMutexAttrT& attribute)
{
    ASSERT_EQUAL(PThreadMutexDestroy(&mutex), PThreadResult::Successful);
    ASSERT_EQUAL(PThreadMutexAttributeDestroy(&attribute), PThreadResult::Successful);
}

void System::PThreadMutexTesting::TryLockTest()
{
    PThreadMutexAttrT attribute{};
    PThreadMutexT mutex{};

    ASSERT_NOT_THROW_EXCEPTION_2(PThreadMutexInitTest, attribute, mutex);

    ASSERT_NOT_THROW_EXCEPTION_1(TryLockTimeoutThreadTest, mutex);

    ASSERT_NOT_THROW_EXCEPTION_1(TryLockSuccessThreadTest, mutex);

    ASSERT_NOT_THROW_EXCEPTION_2(PThreadMutexDestroyTest, mutex, attribute);
}

void System::PThreadMutexTesting::TryLockTimeoutThreadTest(PThreadMutexT& mutex)
{
    ASSERT_EQUAL(PThreadMutexLock(&mutex), PThreadResult::Successful);

    boost::thread thread{ [this, &mutex]() {
        this->TryLockTimeoutTest(&mutex);
    } };

    thread.join();

    ASSERT_EQUAL(PThreadMutexUnlock(&mutex), PThreadResult::Successful);
}

void System::PThreadMutexTesting::TryLockSuccessThreadTest(PThreadMutexT& mutex)
{
    boost::thread thread{ [this, &mutex]() {
        this->TryLockSuccessTest(&mutex);
    } };

    thread.join();
}

void System::PThreadMutexTesting::WaitForMutexTest(PThreadMutexT* mutex)
{
    ASSERT_EQUAL(PThreadMutexLock(mutex), PThreadResult::Successful);

    const auto original = threadSum;

    for (auto i = 0; i < threadCount; ++i)
    {
        --threadSum;
    }

    threadSum = original;

    ++threadSum;

    ASSERT_EQUAL(PThreadMutexUnlock(mutex), PThreadResult::Successful);
}

void System::PThreadMutexTesting::TryLockTimeoutTest(PThreadMutexT* mutex)
{
    ASSERT_UNEQUAL(PThreadMutexTryLock(mutex), PThreadResult::Successful);
}

void System::PThreadMutexTesting::TryLockSuccessTest(PThreadMutexT* mutex)
{
    ASSERT_EQUAL(PThreadMutexTryLock(mutex), PThreadResult::Successful);

    ASSERT_EQUAL(PThreadMutexUnlock(mutex), PThreadResult::Successful);
}
