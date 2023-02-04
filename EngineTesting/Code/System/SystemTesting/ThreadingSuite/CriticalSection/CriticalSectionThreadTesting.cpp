///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 23:11)

#include "CriticalSectionThreadTesting.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/CriticalSectionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CriticalSectionThreadTesting::CriticalSectionThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }, criticalSection{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CriticalSectionThreadTesting)

void System::CriticalSectionThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CriticalSectionThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Delete);
}

void System::CriticalSectionThreadTesting::Init()
{
    ASSERT_TRUE(InitializeSystemCriticalSection(&criticalSection));
}

void System::CriticalSectionThreadTesting::Delete() noexcept
{
    DeleteSystemCriticalSection(&criticalSection);
}

void System::CriticalSectionThreadTesting::ThreadTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnterCriticalSectionThreadTest);

    ASSERT_NOT_THROW_EXCEPTION_0(EnterCriticalSectionThreadFailureTest);

    ASSERT_NOT_THROW_EXCEPTION_0(EnterCriticalSectionThreadSucceedTest);
}

void System::CriticalSectionThreadTesting::EnterCriticalSectionTest() noexcept
{
    EnterSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);
}

void System::CriticalSectionThreadTesting::TryEnterCriticalSectionSucceedTest()
{
    const auto result = TryEnterSystemCriticalSection(&criticalSection);
    ASSERT_TRUE(result);

    if (result)
    {
        LeaveSystemCriticalSection(&criticalSection);
    }
}

void System::CriticalSectionThreadTesting::TryEnterCriticalSectionFailureTest()
{
    const auto result = TryEnterSystemCriticalSection(&criticalSection);
    ASSERT_FALSE(result);

    if (result)
    {
        LeaveSystemCriticalSection(&criticalSection);
    }
}

void System::CriticalSectionThreadTesting::EnterCriticalSectionThreadTest()
{
    std::thread thread{ &ClassType::EnterCriticalSectionTest, this };

    EnterSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);

    thread.join();
}

void System::CriticalSectionThreadTesting::EnterCriticalSectionThreadFailureTest()
{
    EnterSystemCriticalSection(&criticalSection);

    std::thread thread{ &ClassType::TryEnterCriticalSectionFailureTest, this };

    thread.join();

    LeaveSystemCriticalSection(&criticalSection);
}

void System::CriticalSectionThreadTesting::EnterCriticalSectionThreadSucceedTest()
{
    std::thread thread{ &ClassType::TryEnterCriticalSectionSucceedTest, this };

    thread.join();
}
