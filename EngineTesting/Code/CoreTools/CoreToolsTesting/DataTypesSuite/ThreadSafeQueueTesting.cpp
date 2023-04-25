///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:44)

#include "ThreadSafeQueueTesting.h"
#include "CoreTools/DataTypes/ThreadSafeQueueDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <thread>

CoreTools::ThreadSafeQueueTesting::ThreadSafeQueueTesting(const OStreamShared& stream)
    : ParentType{ stream }, threadSafeQueue{ maxNumElements }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadSafeQueueTesting)

void CoreTools::ThreadSafeQueueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadSafeQueueTesting::MainTest()
{
    std::thread thread0{ &ClassType::ThreadSafeQueueTest, this };

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadSafeQueueTest);

    thread0.join();
}

void CoreTools::ThreadSafeQueueTesting::ThreadSafeQueueTest()
{
    ASSERT_EQUAL(threadSafeQueue.GetMaxNumElements(), maxNumElements);

    ASSERT_TRUE(threadSafeQueue.Push(5));

    ASSERT_RANGE(threadSafeQueue.GetNumElements(), 1u, 2u);

    const auto result = threadSafeQueue.Pop();

    ASSERT_EQUAL(result.first, 5);
    ASSERT_TRUE(result.second);

    ASSERT_RANGE(threadSafeQueue.GetNumElements(), 0u, 1u);

    ASSERT_EQUAL(threadSafeQueue.GetMaxNumElements(), maxNumElements);
}