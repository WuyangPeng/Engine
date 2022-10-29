///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:33)

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

using std::max;

System::OpenMutexTesting::OpenMutexTesting(const OStreamShared& stream)
    : ParentType{ stream },
      mutexStandardAccessFlags{ MutexStandardAccess::Delete,
                                MutexStandardAccess::ReadControl,
                                MutexStandardAccess::WriteDac,
                                MutexStandardAccess::WriteOwner,
                                MutexStandardAccess::Synchronize },
      mutexSpecificAccessFlags{ MutexSpecificAccess::Default,
                                MutexSpecificAccess::ModifyState,
                                MutexSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(mutexStandardAccessFlags.size(), mutexSpecificAccessFlags.size()) }
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
    shuffle(mutexStandardAccessFlags.begin(), mutexStandardAccessFlags.end(), randomEngine);
    shuffle(mutexSpecificAccessFlags.begin(), mutexSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    return true;
}

void System::OpenMutexTesting::ThreadTest()
{
    constexpr auto threadCount = 12;
    auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto mutexHandle = CreateSystemMutex(nullptr, true, mutexName.c_str());
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest, this, mutexName));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::OpenMutexTesting::WaitForMutexTest(const String& mutexName)
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto mutexStandardAccess = mutexStandardAccessFlags.at(index % mutexStandardAccessFlags.size());
        auto mutexSpecificAccess = mutexSpecificAccessFlags.at(index % mutexSpecificAccessFlags.size());

        auto mutexHandle = OpenThreadingMutex(mutexStandardAccess, mutexSpecificAccess, true, mutexName.c_str());
        ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

        ASSERT_TRUE(CloseSystemMutex(mutexHandle));
    }
}
