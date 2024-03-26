/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:29)

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
      createMutexContainer{ MutexCreate::Default,
                            MutexCreate::InitialOwner },
      mutexSpecificAccesses{ MutexSpecificAccess::Default,
                             MutexSpecificAccess::ModifyState,
                             MutexSpecificAccess::AllAccess },
      mutexStandardAccesses{ MutexStandardAccess::Delete,
                             MutexStandardAccess::ReadControl,
                             MutexStandardAccess::WriteDac,
                             MutexStandardAccess::WriteOwner,
                             MutexStandardAccess::Synchronize },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ createMutexContainer.size(), mutexSpecificAccesses.size(), mutexStandardAccesses.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    std::ranges::shuffle(mutexStandardAccesses, randomEngine);
    std::ranges::shuffle(mutexSpecificAccesses, randomEngine);
    std::ranges::shuffle(createMutexContainer, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexUseNameTest);

    return true;
}

void System::CreateMutexUseFlagsTesting::CreateMutexTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateMutexTest, index);
    }
}

void System::CreateMutexUseFlagsTesting::DoCreateMutexTest(size_t index)
{
    const auto mutexStandardAccess = mutexStandardAccesses.at(index % mutexStandardAccesses.size());
    const auto mutexSpecificAccess = mutexSpecificAccesses.at(index % mutexSpecificAccesses.size());
    const auto createMutex = createMutexContainer.at(index % createMutexContainer.size());

    const auto mutexHandle = CreateSystemMutex(nullptr, nullptr, createMutex, mutexStandardAccess, mutexSpecificAccess);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::CreateMutexUseFlagsTesting::CreateMutexUseNameTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateMutexUseNameTest, index);
    }
}

void System::CreateMutexUseFlagsTesting::DoCreateMutexUseNameTest(size_t index)
{
    const auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    const auto mutexStandardAccess = mutexStandardAccesses.at(index % mutexStandardAccesses.size());
    const auto mutexSpecificAccess = mutexSpecificAccesses.at(index % mutexSpecificAccesses.size());
    const auto createMutex = createMutexContainer.at(index % createMutexContainer.size());

    const auto mutexHandle = CreateSystemMutex(nullptr, mutexName.c_str(), createMutex, mutexStandardAccess, mutexSpecificAccess);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}
