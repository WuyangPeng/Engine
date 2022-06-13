///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 17:57)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_DETAIL_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_DETAIL_H

#include "InterlockedTesting.h"
#include "System/Threading/InterlockedDetail.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void System::InterlockedTesting::InterlockedTest()
{
    T original{ 5 };
    T value{ original };
    T add{ 10 };

    ASSERT_EQUAL(SystemInterlockedExchangeAdd(&value, add), original);
    ASSERT_EQUAL(value, original + add);

    ASSERT_EQUAL(SystemInterlockedIncrement(&value), static_cast<T>(original + add + 1));
    ASSERT_EQUAL(value, static_cast<T>(original + add + 1));

    ASSERT_EQUAL(SystemInterlockedDecrement(&value), original + add);
    ASSERT_EQUAL(value, original + add);

    ASSERT_EQUAL(SystemInterlockedExchange(&value, original), original + add);
    ASSERT_EQUAL(value, original);

    ASSERT_EQUAL(SystemInterlockedCompareExchange(&value, original - add, original), original);
    ASSERT_EQUAL(value, original - add);

    ASSERT_EQUAL(SystemInterlockedCompareExchange(&value, original, original + add), original - add);
    ASSERT_EQUAL(value, original - add);
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_DETAIL_H