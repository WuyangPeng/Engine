// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 12:28)

#include "CriticalSectionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::CriticalSectionTesting ::CriticalSectionTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_CriticalSection1{}, m_CriticalSection2{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CriticalSectionTesting)
void CoreTools::CriticalSectionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CriticalSectionTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// µ›πÈ≤‚ ‘
void CoreTools::CriticalSectionTesting ::RecursionTest()
{
    m_CriticalSection1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);

    m_CriticalSection1.Delete();
}

void CoreTools::CriticalSectionTesting ::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ m_CriticalSection1 };
    TryScopedMutex holder2{ m_CriticalSection1 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ m_CriticalSection1 };
}

// ∂‡œﬂ≥ÃÀ¯≥…π¶≤‚ ‘
void CoreTools::CriticalSectionTesting ::MultithreadingLockingSuccessTest()
{
    m_CriticalSection1.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);

    m_CriticalSection1.Delete();
}

void CoreTools::CriticalSectionTesting ::CreateLockingSuccessThread()
{
    ASSERT_NOT_THROW_EXCEPTION_1(CreateFourThread, &ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::CriticalSectionTesting ::CreateFourThread(Function function)
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

void CoreTools::CriticalSectionTesting ::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::CriticalSectionTesting ::StaticValueTest()
{
    ScopedMutex holderFirst{ m_CriticalSection1 };

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
void CoreTools::CriticalSectionTesting ::MultithreadingLockingFailureTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);
}

void CoreTools::CriticalSectionTesting ::CreateLockingFailureThread()
{
    ScopedMutex holder(m_CriticalSection2);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateFourThread, &ClassType::MultithreadingFailureCallBack);
}

void CoreTools::CriticalSectionTesting ::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::CriticalSectionTesting ::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockFailureTest);
}

void CoreTools::CriticalSectionTesting ::TryLockFailureTest()
{
    TryScopedMutex holder(m_CriticalSection2);

    ASSERT_FALSE(holder.IsSuccess());
}
