///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:54)

#include "CreateProcessTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateProcessTesting::CreateProcessTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processCreationFlags{ ProcessCreation::DebugProcess,
                            ProcessCreation::DebugOnlyThisProcess,
                            ProcessCreation::CreateSuspended,
                            ProcessCreation::DetachedProcess,
                            ProcessCreation::CreateNewConsole,
                            ProcessCreation::NormalPriorityClass,
                            ProcessCreation::IdlePriorityClass,
                            ProcessCreation::HighPriorityClass,
                            ProcessCreation::RealTimePriorityClass,
                            ProcessCreation::CreateNewProcessGroup,
                            ProcessCreation::CreateUnicodeEnvironment, ProcessCreation::CreateSeparateWowVdm,
                            ProcessCreation::CreateSharedWowVdm,
                            ProcessCreation::CreateForcedos,
                            ProcessCreation::BelowNormalPriorityClass,
                            ProcessCreation::AboveNormalPriorityClass,
                            ProcessCreation::InheritParentAffinity,
                            ProcessCreation::InheritCallerPriority,
                            ProcessCreation::ProcessModeBackgroundBegin,
                            ProcessCreation::ProcessModeBackgroundEnd,
                            ProcessCreation::CreateBreakawayFromJob,
                            ProcessCreation::CreatePreserveCodeAuthzLevel,
                            ProcessCreation::CreateDefaultErrorMode,
                            ProcessCreation::CreateNoWindow,
                            ProcessCreation::ProfileUser,
                            ProcessCreation::ProfileKernel,
                            ProcessCreation::ProfileServer,
                            ProcessCreation::CreateIgnoreSystemDefault },
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest"s) + GetEngineeringSuffix() + GetEngineeringExeSuffix() }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateProcessTesting)

void System::CreateProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateProcessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProcessTest);
}

void System::CreateProcessTesting::ProcessTest()
{
    for (auto processCreation : processCreationFlags)
    {
        ProcessStartupinfo startupInfo{};
        ProcessInformation processInformation{};

        ASSERT_TRUE(CreateSystemProcess(processFullPath.c_str(), nullptr, nullptr, nullptr, true, processCreation, nullptr, nullptr, &startupInfo, &processInformation));

        if (processCreation == ProcessCreation::CreateSuspended)
        {
            ASSERT_EQUAL(ResumeSystemThread(processInformation.hThread), 1u);
        }

        ASSERT_EQUAL(GetProcessHandleID(processInformation.hProcess), processInformation.dwProcessId);

        ASSERT_TRUE(CloseSystemThread(processInformation.hThread));
        ASSERT_TRUE(CloseSystemProcess(processInformation.hProcess));
    }
}
