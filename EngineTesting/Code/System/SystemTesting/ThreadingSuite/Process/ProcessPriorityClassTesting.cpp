///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:16)

#include "ProcessPriorityClassTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Threading/Using/ProcessUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ProcessPriorityClassTesting::ProcessPriorityClassTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processCreations{ ProcessCreation::AboveNormalPriorityClass,
                        ProcessCreation::BelowNormalPriorityClass,
                        ProcessCreation::HighPriorityClass,
                        ProcessCreation::IdlePriorityClass,
                        ProcessCreation::NormalPriorityClass,
                        ProcessCreation::RealTimePriorityClass }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ProcessPriorityClassTesting)

void System::ProcessPriorityClassTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ProcessPriorityClassTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PriorityClassTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BackgroundProcessingTest);
}

void System::ProcessPriorityClassTesting::PriorityClassTest()
{
    for (auto processPriority : processCreations)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoPriorityClassTest, processPriority);
    }
}

void System::ProcessPriorityClassTesting::BackgroundProcessingTest()
{
    const auto priorityClassFlag = GetProcessPriorityClass(GetCurrentProcessHandle());

    ASSERT_TRUE(SetProcessPriorityClass(GetCurrentProcessHandle(), ProcessCreation::ProcessModeBackgroundBegin));

    ASSERT_ENUM_UNEQUAL(priorityClassFlag, GetProcessPriorityClass(GetCurrentProcessHandle()));

    ASSERT_TRUE(SetProcessPriorityClass(GetCurrentProcessHandle(), ProcessCreation::ProcessModeBackgroundEnd));

    ASSERT_ENUM_EQUAL(priorityClassFlag, GetProcessPriorityClass(GetCurrentProcessHandle()));
}

void System::ProcessPriorityClassTesting::DoPriorityClassTest(ProcessCreation processPriority)
{
    constexpr auto normalPriorityClassFlag = ProcessCreation::NormalPriorityClass;
    constexpr auto creationFlag = normalPriorityClassFlag | ProcessCreation::CreateSuspended;

    ProcessStartupInfo startupInfo{};
    ProcessInformation processInformation{};

    ASSERT_TRUE(CreateSystemProcess(GetProcessFullPath().c_str(), nullptr, nullptr, nullptr, true, creationFlag, nullptr, nullptr, &startupInfo, &processInformation));

    ASSERT_ENUM_EQUAL(normalPriorityClassFlag, GetProcessPriorityClass(processInformation.hProcess));
    ASSERT_TRUE(SetProcessPriorityClass(processInformation.hProcess, processPriority));

    if (processPriority != ProcessCreation::RealTimePriorityClass)
    {
        ASSERT_ENUM_EQUAL(processPriority, GetProcessPriorityClass(processInformation.hProcess));
    }

    ASSERT_EQUAL(ResumeSystemThread(processInformation.hThread), 1u);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTest, processInformation);
}
