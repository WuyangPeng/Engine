///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/02 09:13)

#include "SemaphoreTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SemaphoreTesting::SemaphoreTesting(const OStreamShared& stream)
    : ParentType{ stream }, semaphore0{ 1, 5 }, semaphore1{ 0, 6 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SemaphoreTesting)

void CoreTools::SemaphoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SemaphoreTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateThread);
}

void CoreTools::SemaphoreTesting::CreateThread()
{
    auto thread = ThreadGroup::Create();

    for (auto i = 0; i < threadSize; ++i)
    {
        thread.AddThread(&ClassType::ReadThread, this);
    }

    thread.AddThread(&ClassType::WriteThread, this);
}

void CoreTools::SemaphoreTesting::ReadThread()
{
    semaphore1.Wait();

    ASSERT_EQUAL(semaphore0.GetCurrentCount(), 0);
    ASSERT_EQUAL(semaphore0.GetMaximumCount(), 5);
    ASSERT_RANGE(semaphore1.GetCurrentCount(), 0, threadSize - 1);
    ASSERT_EQUAL(semaphore1.GetMaximumCount(), 6);
}

void CoreTools::SemaphoreTesting::WriteThread()
{
    ASSERT_EQUAL(semaphore0.GetCurrentCount(), 1);
    ASSERT_EQUAL(semaphore0.GetMaximumCount(), 5);
    ASSERT_EQUAL(semaphore1.GetCurrentCount(), 0);
    ASSERT_EQUAL(semaphore1.GetMaximumCount(), 6);

    semaphore0.Wait();

    ASSERT_EQUAL(semaphore0.GetCurrentCount(), 0);
    ASSERT_EQUAL(semaphore0.GetMaximumCount(), 5);
    ASSERT_EQUAL(semaphore1.GetCurrentCount(), 0);
    ASSERT_EQUAL(semaphore1.GetMaximumCount(), 6);

    semaphore1.Release(threadSize);
}
