// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 13:00)

#include "NullMutexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <thread>

using std::ostream;
using std::thread;

CoreTools::NullMutexTesting ::NullMutexTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_WindowsMutex1{ MutexCreate::UseNull }, m_WindowsMutex2{ MutexCreate::UseNull }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullMutexTesting)
void CoreTools::NullMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NullMutexTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingSuccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultithreadingLockingFailureTest);
}

// µ›πÈ≤‚ ‘
void CoreTools::NullMutexTesting ::RecursionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRecursionTestHolder);
}

void CoreTools::NullMutexTesting ::CreateRecursionTestHolder()
{
    ScopedMutex holder1{ m_WindowsMutex1 };
    TryScopedMutex holder2{ m_WindowsMutex1 };

    ASSERT_TRUE(holder2.IsSuccess());

    ScopedMutex holder3{ m_WindowsMutex1 };
}

// ∂‡œﬂ≥ÃÀ¯≥…π¶≤‚ ‘
void CoreTools::NullMutexTesting ::MultithreadingLockingSuccessTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingSuccessThread);
}

void CoreTools::NullMutexTesting ::CreateLockingSuccessThread()
{
    CreateFourThread(&ClassType::MultithreadingSuccessCallBack);
}

void CoreTools::NullMutexTesting ::CreateFourThread(Function function)
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

void CoreTools::NullMutexTesting ::MultithreadingSuccessCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticValueTest);
}

void CoreTools::NullMutexTesting ::StaticValueTest()
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

            testValue = outerLoop - innerLoop;

            testValue = outerLoop * innerLoop;
        }
    }

    testValue = original;
}

// ∂‡œﬂ≥ÃÀ¯ ß∞‹≤‚ ‘
void CoreTools::NullMutexTesting ::MultithreadingLockingFailureTest()
{
    m_WindowsMutex2.Initialize();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateLockingFailureThread);

    m_WindowsMutex2.Delete();
}

void CoreTools::NullMutexTesting ::CreateLockingFailureThread()
{
    ScopedMutex holder{ m_WindowsMutex2 };

    CreateFourThread(&ClassType::MultithreadingFailureCallBack);
}

void CoreTools::NullMutexTesting ::MultithreadingFailureCallBack()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFailureCallBackHolder);
}

void CoreTools::NullMutexTesting ::CreateFailureCallBackHolder()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TryLockTest);
}

void CoreTools::NullMutexTesting ::TryLockTest()
{
    TryScopedMutex holder{ m_WindowsMutex2 };

    ASSERT_TRUE(holder.IsSuccess());
}
