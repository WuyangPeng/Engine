﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/28 12:53)

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
    std::thread thread{ &ClassType::ThreadSafeQueueTest, this };

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadSafeQueueTest);

    thread.join();
}

void CoreTools::ThreadSafeQueueTesting::ThreadSafeQueueTest()
{
    ASSERT_EQUAL(threadSafeQueue.GetMaxNumElements(), maxNumElements);
    ASSERT_TRUE(threadSafeQueue.Push(5));
    ASSERT_RANGE(threadSafeQueue.GetNumElements(), 1, 2);

    const auto [element, result] = threadSafeQueue.Pop();

    ASSERT_EQUAL(element, 5);
    ASSERT_TRUE(result);

    ASSERT_RANGE(threadSafeQueue.GetNumElements(), 0, 1);
    ASSERT_EQUAL(threadSafeQueue.GetMaxNumElements(), maxNumElements);
}