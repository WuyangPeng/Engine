/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:26)

#include "OpenProcessTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenProcessTesting::OpenProcessTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processStandardAccesses{ ProcessStandardAccess::Delete,
                               ProcessStandardAccess::ReadControl,
                               ProcessStandardAccess::WriteDac,
                               ProcessStandardAccess::WriteOwner,
                               ProcessStandardAccess::Synchronize },
      processSpecificAccesses{ ProcessSpecificAccess::Terminate,
                               ProcessSpecificAccess::CreateThread,
                               ProcessSpecificAccess::SetSessionId,
                               ProcessSpecificAccess::VmOperation,
                               ProcessSpecificAccess::VmRead,
                               ProcessSpecificAccess::VmWrite,
                               ProcessSpecificAccess::DupHandle,
                               ProcessSpecificAccess::CreateProcess,
                               ProcessSpecificAccess::SetQuota,
                               ProcessSpecificAccess::SetInformation,
                               ProcessSpecificAccess::QueryInformation,
                               ProcessSpecificAccess::SuspendResume,
                               ProcessSpecificAccess::QueryLimitedInformation,
                               ProcessSpecificAccess::AllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(processStandardAccesses.size(), processSpecificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenProcessTesting)

void System::OpenProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenProcessTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenProcessTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(processStandardAccesses, randomEngine);
    std::ranges::shuffle(processSpecificAccesses, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenProcessTest);

    return true;
}

void System::OpenProcessTesting::OpenProcessTest()
{
    constexpr auto creationFlag = ProcessCreation::NormalPriorityClass;

    ProcessStartupInfo startupInfo{};
    ProcessInformation processInformation{};

    ASSERT_TRUE(CreateSystemProcess(GetProcessFullPath().c_str(), nullptr, nullptr, nullptr, true, creationFlag, nullptr, nullptr, &startupInfo, &processInformation));

    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoOpenProcessTest, index, processInformation);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTest, processInformation);
}

void System::OpenProcessTesting::DoOpenProcessTest(size_t index, const ProcessInformation& processInformation)
{
    const auto processStandardAccessFlag = processStandardAccesses.at(index % processStandardAccesses.size());
    const auto processSpecificAccessFlag = processSpecificAccesses.at(index % processSpecificAccesses.size());

    const auto processHandle = OpenSystemProcess(processStandardAccessFlag, processSpecificAccessFlag, true, processInformation.dwProcessId);

    ASSERT_UNEQUAL_NULL_PTR(processHandle);

    ASSERT_TRUE(CloseSystemProcess(processHandle));
}
