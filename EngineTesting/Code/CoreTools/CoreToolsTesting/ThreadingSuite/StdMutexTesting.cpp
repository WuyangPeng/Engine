// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 13:03)

#include "StdMutexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::StdMutexTesting ::StdMutexTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_WindowsMutex1{ MutexCreate::UseStd }, m_WindowsMutex2{ MutexCreate::UseStd }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdMutexTesting)
void CoreTools::StdMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StdMutexTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// µ›πÈ≤‚ ‘
void CoreTools::StdMutexTesting ::RecursionTest()
{
    ASSERT_THROW_EXCEPTION_0(CreateRecursionTestFailureHolder);
}

void CoreTools::StdMutexTesting ::CreateRecursionTestFailureHolder()
{
    ScopedMutex holder1{ m_WindowsMutex1 };
    TryScopedMutex holder2{ m_WindowsMutex1 };

    ASSERT_FALSE(holder2.IsSuccess());

    ScopedMutex holder3{ m_WindowsMutex1 };
}

// ∂‡œﬂ≥ÃÀ¯≥…π¶≤‚ ‘
void CoreTools::StdMutexTesting ::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::StdMutexTesting ::CreateLockingSuccessThread()
{
    CreateFourThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::StdMutexTesting ::CreateFourThread(Function function)
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

void CoreTools::StdMutexTesting ::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::StdMutexTesting ::StaticValueTest()
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
void CoreTools::StdMutexTesting ::MultithreadingLockingFailureTest()
{
    m_WindowsMutex2.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    m_WindowsMutex2.Delete();
}

void CoreTools::StdMutexTesting ::CreateLockingFailureThread()
{
    ScopedMutex holder{ m_WindowsMutex2 };

    CreateFourThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::StdMutexTesting ::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::StdMutexTesting ::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::StdMutexTesting ::TryLockFailureTest()
{
    TryScopedMutex holder{ m_WindowsMutex2 };

    ASSERT_FALSE(holder.IsSuccess());
}
