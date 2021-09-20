// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 12:26)

#include "BoostRecursiveMutexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::BoostRecursiveMutexTesting ::BoostRecursiveMutexTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_WindowsMutex1{ MutexCreate::UseBoostRecursive }, m_WindowsMutex2{ MutexCreate::UseBoostRecursive }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostRecursiveMutexTesting)
void CoreTools::BoostRecursiveMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BoostRecursiveMutexTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// µ›πÈ≤‚ ‘
void CoreTools::BoostRecursiveMutexTesting ::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::BoostRecursiveMutexTesting ::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ m_WindowsMutex1 };
    TryScopedMutex holder2{ m_WindowsMutex1 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ m_WindowsMutex1 };
}

// ∂‡œﬂ≥ÃÀ¯≥…π¶≤‚ ‘
void CoreTools::BoostRecursiveMutexTesting ::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::BoostRecursiveMutexTesting ::CreateLockingSuccessThread()
{
    CreateFourThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::BoostRecursiveMutexTesting ::CreateFourThread(Function function)
{
    thread thread1{ function, this };
    thread thread2{ function, this };
    thread thread3{ function, this };
    thread thread4{ function, this };
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
}

void CoreTools::BoostRecursiveMutexTesting ::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::BoostRecursiveMutexTesting ::StaticValueTest()
{
    ScopedMutex holderFirst{ m_WindowsMutex1 };

    constexpr auto original = 0;
    static auto testValue = original;

    const auto loopCount = GetTestLoopCount();

    for (auto outerLoop = 0; outerLoop < loopCount; ++outerLoop)
    {
        for (auto innerLoop = 0; innerLoop < loopCount; ++innerLoop)
        {
            testValue = outerLoop + innerLoop;
            ASSERT_EQUAL(testValue, outerLoop + innerLoop);

            testValue = outerLoop - innerLoop;
            ASSERT_EQUAL(testValue, outerLoop - innerLoop);

            testValue = outerLoop * innerLoop;
            ASSERT_EQUAL(testValue, outerLoop * innerLoop);
        }
    }

    testValue = original;
    ASSERT_EQUAL(testValue, original);
}

// ∂‡œﬂ≥ÃÀ¯ ß∞‹≤‚ ‘
void CoreTools::BoostRecursiveMutexTesting ::MultithreadingLockingFailureTest()
{
    m_WindowsMutex2.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    m_WindowsMutex2.Delete();
}

void CoreTools::BoostRecursiveMutexTesting ::CreateLockingFailureThread()
{
    ScopedMutex holder{ m_WindowsMutex2 };

    CreateFourThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::BoostRecursiveMutexTesting ::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::BoostRecursiveMutexTesting ::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::BoostRecursiveMutexTesting ::TryLockFailureTest()
{
    TryScopedMutex holder{ m_WindowsMutex2 };

    ASSERT_FALSE(holder.IsSuccess());
}
