///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:43)

#include "CriticalSectionThreadTesting.h"
#include "System/Threading/CriticalSection.h"
#include "System/Threading/Flags/CriticalSectionFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

using std::thread;

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
    thread thread0{ &ClassType::EnterCriticalSectionTest, this };

    EnterSystemCriticalSection(&criticalSection);

    LeaveSystemCriticalSection(&criticalSection);

    thread0.join();

    EnterSystemCriticalSection(&criticalSection);

    thread thread1{ &ClassType::TryEnterCriticalSectionFailureTest, this };

    thread1.join();

    LeaveSystemCriticalSection(&criticalSection);

    thread thread2{ &ClassType::TryEnterCriticalSectionSucceedTest, this };

    thread2.join();
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