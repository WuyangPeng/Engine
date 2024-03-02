///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:15)

#include "CreateProcessTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateProcessTesting::CreateProcessTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processCreations{ ProcessCreation::DebugProcess,
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
                        ProcessCreation::CreateForceDos,
                        ProcessCreation::BelowNormalPriorityClass,
                        ProcessCreation::AboveNormalPriorityClass,
                        ProcessCreation::InheritParentAffinity,
                        ProcessCreation::InheritCallerPriority,
                        ProcessCreation::ProcessModeBackgroundBegin,
                        ProcessCreation::ProcessModeBackgroundEnd,
                        ProcessCreation::CreateBreakawayFromJob,
                        ProcessCreation::CreatePreserveCodeAuthorizationLevel,
                        ProcessCreation::CreateDefaultErrorMode,
                        ProcessCreation::CreateNoWindow,
                        ProcessCreation::ProfileUser,
                        ProcessCreation::ProfileKernel,
                        ProcessCreation::ProfileServer,
                        ProcessCreation::CreateIgnoreSystemDefault }
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
    for (auto processCreation : processCreations)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoProcessTest, processCreation);
    }
}

void System::CreateProcessTesting::DoProcessTest(ProcessCreation processCreation)
{
    ProcessStartupInfo startupInfo{};
    ProcessInformation processInformation{};

    ASSERT_TRUE(CreateSystemProcess(GetProcessFullPath().c_str(), nullptr, nullptr, nullptr, true, processCreation, nullptr, nullptr, &startupInfo, &processInformation));

    if ((processCreation & ProcessCreation::CreateSuspended) == ProcessCreation::CreateSuspended)
    {
        ASSERT_EQUAL(ResumeSystemThread(processInformation.hThread), 1u);
    }

    ASSERT_EQUAL(GetProcessHandleId(processInformation.hProcess), processInformation.dwProcessId);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTest, processInformation);
}
