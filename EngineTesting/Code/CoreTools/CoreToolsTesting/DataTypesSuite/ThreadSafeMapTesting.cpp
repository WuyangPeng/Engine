///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:43)

#include "ThreadSafeMapTesting.h"
#include "CoreTools/DataTypes/ThreadSafeMapDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

CoreTools::ThreadSafeMapTesting::ThreadSafeMapTesting(const OStreamShared& stream)
    : ParentType{ stream }, threadSafeMap{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadSafeMapTesting)

void CoreTools::ThreadSafeMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadSafeMapTesting::MainTest()
{
    std::thread thread0{ &ClassType::ThreadSafeMapTest, this };

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadSafeMapTest);

    thread0.join();

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadSafeMapRemoveTest);
}

void CoreTools::ThreadSafeMapTesting::ThreadSafeMapTest()
{
    threadSafeMap.Insert(1, 2);

    ASSERT_TRUE(threadSafeMap.HasElements());

    ASSERT_TRUE(threadSafeMap.Exists(1));

    ASSERT_EQUAL(threadSafeMap.Get(1), 2);

    threadSafeMap.Insert(2, 3);

    const auto gather = threadSafeMap.GatherAll();

    ASSERT_EQUAL(gather.size(), 2u);
}

void CoreTools::ThreadSafeMapTesting::ThreadSafeMapRemoveTest()
{
    threadSafeMap.Insert(3, 4);

    ASSERT_TRUE(threadSafeMap.Remove(3));

    threadSafeMap.RemoveAll();

    ASSERT_FALSE(threadSafeMap.HasElements());
}
