///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 14:38)

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

    thread.AddThread(&ClassType::WirteThread, this);
}

void CoreTools::SemaphoreTesting::ReadThread()
{
    semaphore1.Wait();

    ASSERT_EQUAL(semaphore0.GetCurrentCount(), 0);
    ASSERT_EQUAL(semaphore0.GetMaximumCount(), 5);
    ASSERT_RANGE(semaphore1.GetCurrentCount(), 0, threadSize - 1);
    ASSERT_EQUAL(semaphore1.GetMaximumCount(), 6);
}

void CoreTools::SemaphoreTesting::WirteThread()
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
