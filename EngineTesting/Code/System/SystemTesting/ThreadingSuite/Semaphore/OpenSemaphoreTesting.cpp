///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/27 15:04)

#include "OpenSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::OpenSemaphoreTesting::OpenSemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream },
      semaphoreStandardAccessFlags{ MutexStandardAccess::Delete,
                                    MutexStandardAccess::ReadControl,
                                    MutexStandardAccess::WriteDac,
                                    MutexStandardAccess::WriteOwner,
                                    MutexStandardAccess::Synchronize },
      semaphoreSpecificAccessFlags{ SemaphoreSpecificAccess::Default,
                                    SemaphoreSpecificAccess::ModifyState,
                                    SemaphoreSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(semaphoreStandardAccessFlags.size(), semaphoreSpecificAccessFlags.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenSemaphoreTesting)

void System::OpenSemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenSemaphoreTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenSemaphoreTesting::RandomShuffleFlags()
{
    shuffle(semaphoreStandardAccessFlags.begin(), semaphoreStandardAccessFlags.end(), randomEngine);
    shuffle(semaphoreSpecificAccessFlags.begin(), semaphoreSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenSemaphoreTesting::ThreadTest()
{
    constexpr WindowsLong maxSemphoreCount{ 10 };
    constexpr auto threadCount = 12;
    auto semaphoreName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto semaphoreHandle = CreateSystemSemaphore(nullptr, maxSemphoreCount, maxSemphoreCount, semaphoreName.c_str());
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest, this, semaphoreName));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));

    auto semaphoreStandardAccess = semaphoreStandardAccessFlags.at(0);
    auto semaphoreSpecificAccess = semaphoreSpecificAccessFlags.at(0);

    auto openSemaphoreHandle = OpenSystemSemaphore(semaphoreStandardAccess, semaphoreSpecificAccess, true, semaphoreName.c_str());
    ASSERT_EQUAL_NULL_PTR(openSemaphoreHandle);
}

void System::OpenSemaphoreTesting::WaitForSemaphoreTest(const String& semaphoreName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto semaphoreStandardAccess = semaphoreStandardAccessFlags.at(index % semaphoreStandardAccessFlags.size());
        auto semaphoreSpecificAccess = semaphoreSpecificAccessFlags.at(index % semaphoreSpecificAccessFlags.size());

        auto semaphoreHandle = OpenSystemSemaphore(semaphoreStandardAccess, semaphoreSpecificAccess, true, semaphoreName.c_str());
        ASSERT_UNEQUAL_NULL_PTR(semaphoreHandle);

        ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));
    }
}
