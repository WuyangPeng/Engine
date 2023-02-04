///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 15:31)

#include "OpenSemaphoreTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Semaphore.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenSemaphoreTesting::OpenSemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream },
      semaphoreStandardAccesses{ MutexStandardAccess::Delete,
                                 MutexStandardAccess::ReadControl,
                                 MutexStandardAccess::WriteDac,
                                 MutexStandardAccess::WriteOwner,
                                 MutexStandardAccess::Synchronize },
      semaphoreSpecificAccesses{ SemaphoreSpecificAccess::Default,
                                 SemaphoreSpecificAccess::ModifyState,
                                 SemaphoreSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(semaphoreStandardAccesses.size(), semaphoreSpecificAccesses.size()) }
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
    shuffle(semaphoreStandardAccesses.begin(), semaphoreStandardAccesses.end(), randomEngine);
    shuffle(semaphoreSpecificAccesses.begin(), semaphoreSpecificAccesses.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenSemaphoreTesting::ThreadTest()
{
    constexpr WindowsLong maxSemphoreCount{ 10 };

    const auto semaphoreName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    const auto semaphoreHandle = CreateSystemSemaphore(nullptr, maxSemphoreCount, maxSemphoreCount, semaphoreName.c_str());
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, semaphoreName);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSemaphoreTest, semaphoreHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(OpenSemaphoreFail, semaphoreName);
}

void System::OpenSemaphoreTesting::WaitForSemaphoreTest(const String& semaphoreName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoWaitForSemaphoreTest, index, semaphoreName);
    }
}

void System::OpenSemaphoreTesting::OpenSemaphoreFail(const String& semaphoreName)
{
    const auto semaphoreStandardAccess = semaphoreStandardAccesses.at(0);
    const auto semaphoreSpecificAccess = semaphoreSpecificAccesses.at(0);

    const auto openSemaphoreHandle = OpenSystemSemaphore(semaphoreStandardAccess, semaphoreSpecificAccess, true, semaphoreName.c_str());
    ASSERT_EQUAL_NULL_PTR(openSemaphoreHandle);
}

void System::OpenSemaphoreTesting::CreateThread(const String& semaphoreName)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForSemaphoreTest, this, semaphoreName));
    }

    threadGroup.join_all();
}

void System::OpenSemaphoreTesting::DoWaitForSemaphoreTest(size_t index, const String& semaphoreName)
{
    const auto semaphoreStandardAccess = semaphoreStandardAccesses.at(index % semaphoreStandardAccesses.size());
    const auto semaphoreSpecificAccess = semaphoreSpecificAccesses.at(index % semaphoreSpecificAccesses.size());

    const auto semaphoreHandle = OpenSystemSemaphore(semaphoreStandardAccess, semaphoreSpecificAccess, true, semaphoreName.c_str());
    ASSERT_UNEQUAL_NULL_PTR(semaphoreHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSemaphoreTest, semaphoreHandle);
}
