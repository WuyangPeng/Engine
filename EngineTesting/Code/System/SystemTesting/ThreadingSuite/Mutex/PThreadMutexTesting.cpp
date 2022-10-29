///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:33)

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
    constexpr auto threadCount = 12;

    PthreadMutexattrT attribute{};
    PthreadMutexT mutex{};

    ASSERT_ENUM_EQUAL(PthreadMutexAttributeInit(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeSetType(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexInit(&attribute, &mutex), PthreadResult::Successful);

    threadSum = 0;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, &mutex));
    }

    threadGroup.join_all();

    ASSERT_EQUAL(threadSum, threadCount);

    ASSERT_ENUM_EQUAL(PthreadMutexDestroy(&mutex), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeDestroy(&attribute), PthreadResult::Successful);
}

void System::PThreadMutexTesting::TrylockTest()
{
    PthreadMutexattrT attribute{};
    PthreadMutexT mutex{};

    ASSERT_ENUM_EQUAL(PthreadMutexAttributeInit(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeSetType(&attribute), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexInit(&attribute, &mutex), PthreadResult::Successful);

    ASSERT_ENUM_EQUAL(PthreadMutexLock(&mutex), PthreadResult::Successful);

    boost::thread thread0{ boost::bind(&ClassType::TrylockTimeoutTest, this, &mutex) };

    thread0.join();

    ASSERT_ENUM_EQUAL(PthreadMutexUnlock(&mutex), PthreadResult::Successful);

    boost::thread thread1{ boost::bind(&ClassType::TrylockSuccessTest, this, &mutex) };

    thread1.join();

    ASSERT_ENUM_EQUAL(PthreadMutexDestroy(&mutex), PthreadResult::Successful);
    ASSERT_ENUM_EQUAL(PthreadMutexAttributeDestroy(&attribute), PthreadResult::Successful);
}

void System::PThreadMutexTesting::WaitForMutexTest(PthreadMutexT* mutex)
{
    constexpr auto loopCount = 12;

    ASSERT_ENUM_EQUAL(PthreadMutexLock(mutex), PthreadResult::Successful);

    const auto original = threadSum;

    for (auto i = 0; i < loopCount; ++i)
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
