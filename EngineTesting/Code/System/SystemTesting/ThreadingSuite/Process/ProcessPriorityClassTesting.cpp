///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:52)

#include "ProcessPriorityClassTesting.h"
#include "System/Threading/Flags/ProcessFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Threading/Using/ProcessUsing.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::ProcessPriorityClassTesting::ProcessPriorityClassTesting(const OStreamShared& stream)
    : ParentType{ stream },
      processCreationFlags{ ProcessCreation::AboveNormalPriorityClass,
                            ProcessCreation::BelowNormalPriorityClass,
                            ProcessCreation::HighPriorityClass,
                            ProcessCreation::IdlePriorityClass,
                            ProcessCreation::NormalPriorityClass,
                            ProcessCreation::RealTimePriorityClass },
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest"s) + GetEngineeringSuffix() + GetEngineeringExeSuffix() }
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
    constexpr auto normalPriorityClassFlag = ProcessCreation::NormalPriorityClass;
    constexpr auto creationFlag = normalPriorityClassFlag | ProcessCreation::CreateSuspended;

    for (auto processPriority : processCreationFlags)
    {
        ProcessStartupinfo startupInfo{};
        ProcessInformation processInformation{};

        ASSERT_TRUE(CreateSystemProcess(processFullPath.c_str(), nullptr, nullptr, nullptr, true, creationFlag, nullptr, nullptr, &startupInfo, &processInformation));

        ASSERT_ENUM_EQUAL(normalPriorityClassFlag, GetProcessPriorityClass(processInformation.hProcess));
        ASSERT_TRUE(SetProcessPriorityClass(processInformation.hProcess, processPriority));

        if (processPriority != ProcessCreation::RealTimePriorityClass)
        {
            ASSERT_ENUM_EQUAL(processPriority, GetProcessPriorityClass(processInformation.hProcess));
        }

        ASSERT_EQUAL(ResumeSystemThread(processInformation.hThread), 1u);

        ASSERT_TRUE(CloseSystemThread(processInformation.hThread));
        ASSERT_TRUE(CloseSystemProcess(processInformation.hProcess));
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
