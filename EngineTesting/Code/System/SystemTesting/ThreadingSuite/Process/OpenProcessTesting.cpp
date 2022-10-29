///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:54)

#include "OpenProcessTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;
using namespace std::literals;

System::OpenProcessTesting::OpenProcessTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processStandardAccessFlags{ ProcessStandardAccess::Delete,
                                  ProcessStandardAccess::ReadControl,
                                  ProcessStandardAccess::WriteDac,
                                  ProcessStandardAccess::WriteOwner,
                                  ProcessStandardAccess::Synchronize },
      processSpecificAccessFlags{ ProcessSpecificAccess::Terminate,
                                  ProcessSpecificAccess::CreateThread,
                                  ProcessSpecificAccess::SetSessionID,
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
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest"s) + GetEngineeringSuffix() + GetEngineeringExeSuffix() },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(processStandardAccessFlags.size(), processSpecificAccessFlags.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    shuffle(processStandardAccessFlags.begin(), processStandardAccessFlags.end(), randomEngine);
    shuffle(processSpecificAccessFlags.begin(), processSpecificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenProcessTest);

    return true;
}

void System::OpenProcessTesting::OpenProcessTest()
{
    const auto creationFlag = ProcessCreation::NormalPriorityClass;

    ProcessStartupinfo startupInfo{};
    ProcessInformation processInformation{};

    ASSERT_TRUE(CreateSystemProcess(processFullPath.c_str(), nullptr, nullptr, nullptr, true, creationFlag, nullptr, nullptr, &startupInfo, &processInformation));

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto processStandardAccessFlag = processStandardAccessFlags.at(index % processStandardAccessFlags.size());
        auto processSpecificAccessFlag = processSpecificAccessFlags.at(index % processSpecificAccessFlags.size());

        auto processHandle = OpenSystemProcess(processStandardAccessFlag, processSpecificAccessFlag, true, processInformation.dwProcessId);

        ASSERT_UNEQUAL_NULL_PTR(processHandle);

        ASSERT_TRUE(CloseSystemProcess(processHandle));
    }

    ASSERT_TRUE(CloseSystemThread(processInformation.hThread));
    ASSERT_TRUE(CloseSystemProcess(processInformation.hProcess));
}
