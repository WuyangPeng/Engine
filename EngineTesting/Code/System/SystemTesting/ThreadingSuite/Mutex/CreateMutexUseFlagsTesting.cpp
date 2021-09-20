///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 10:48)

#include "CreateMutexUseFlagsTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateMutexUseFlagsTesting::CreateMutexUseFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      createMutexFlags{ MutexCreate::Default,
                        MutexCreate::InitialOwner },
      mutexSpecificAccessFlags{ MutexSpecificAccess::Default,
                                MutexSpecificAccess::ModifyState,
                                MutexSpecificAccess::AllAccess },
      mutexStandardAccessFlags{ MutexStandardAccess::Delete,
                                MutexStandardAccess::ReadControl,
                                MutexStandardAccess::WriteDac,
                                MutexStandardAccess::WriteOwner,
                                MutexStandardAccess::Synchronize },
      maxSize{ CoreTools::MaxElement<size_t>({ createMutexFlags.size(), mutexSpecificAccessFlags.size(), mutexStandardAccessFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateMutexUseFlagsTesting)

void System::CreateMutexUseFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateMutexUseFlagsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateMutexUseFlagsTesting::RandomShuffleFlags()
{
    shuffle(mutexStandardAccessFlags.begin(), mutexStandardAccessFlags.end(), randomEngine);
    shuffle(mutexSpecificAccessFlags.begin(), mutexSpecificAccessFlags.end(), randomEngine);
    shuffle(createMutexFlags.begin(), createMutexFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexUseNameTest);

    return true;
}

void System::CreateMutexUseFlagsTesting::CreateMutexTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto mutexStandardAccess = mutexStandardAccessFlags.at(index % mutexStandardAccessFlags.size());
        auto mutexSpecificAccess = mutexSpecificAccessFlags.at(index % mutexSpecificAccessFlags.size());
        auto createMutex = createMutexFlags.at(index % createMutexFlags.size());

        auto mutexHandle = CreateSystemMutex(nullptr, nullptr, createMutex, mutexStandardAccess, mutexSpecificAccess);
        ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

        ASSERT_TRUE(CloseSystemMutex(mutexHandle));
    }
}

void System::CreateMutexUseFlagsTesting::CreateMutexUseNameTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

        auto mutexStandardAccess = mutexStandardAccessFlags.at(index % mutexStandardAccessFlags.size());
        auto mutexSpecificAccess = mutexSpecificAccessFlags.at(index % mutexSpecificAccessFlags.size());
        auto createMutex = createMutexFlags.at(index % createMutexFlags.size());

        auto mutexHandle = CreateSystemMutex(nullptr, mutexName.c_str(), createMutex, mutexStandardAccess, mutexSpecificAccess);
        ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

        ASSERT_TRUE(CloseSystemMutex(mutexHandle));
    }
}
