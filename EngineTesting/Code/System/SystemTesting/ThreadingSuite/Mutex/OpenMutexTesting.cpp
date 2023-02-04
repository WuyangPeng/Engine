///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 10:19)

#include "OpenMutexTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenMutexTesting::OpenMutexTesting(const OStreamShared& stream)
    : ParentType{ stream },
      mutexStandardAccesses{ MutexStandardAccess::Delete,
                             MutexStandardAccess::ReadControl,
                             MutexStandardAccess::WriteDac,
                             MutexStandardAccess::WriteOwner,
                             MutexStandardAccess::Synchronize },
      mutexSpecificAccesses{ MutexSpecificAccess::Default,
                             MutexSpecificAccess::ModifyState,
                             MutexSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(mutexStandardAccesses.size(), mutexSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenMutexTesting)

void System::OpenMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenMutexTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenMutexTesting::RandomShuffleFlags()
{
    shuffle(mutexStandardAccesses.begin(), mutexStandardAccesses.end(), randomEngine);
    shuffle(mutexSpecificAccesses.begin(), mutexSpecificAccesses.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenMutexTesting::ThreadTest()
{
    const auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    const auto mutexHandle = CreateSystemMutex(nullptr, true, mutexName.c_str());
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThreadTest, mutexName);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::OpenMutexTesting::WaitForMutexTest(const String& mutexName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoWaitForMutexTest, index, mutexName);
    }
}

void System::OpenMutexTesting::CreateThreadTest(const String& mutexName)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, mutexName));
    }

    threadGroup.join_all();
}

void System::OpenMutexTesting::DoWaitForMutexTest(size_t index, const String& mutexName)
{
    const auto mutexStandardAccess = mutexStandardAccesses.at(index % mutexStandardAccesses.size());
    const auto mutexSpecificAccess = mutexSpecificAccesses.at(index % mutexSpecificAccesses.size());

    const auto mutexHandle = OpenThreadingMutex(mutexStandardAccess, mutexSpecificAccess, true, mutexName.c_str());
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}
