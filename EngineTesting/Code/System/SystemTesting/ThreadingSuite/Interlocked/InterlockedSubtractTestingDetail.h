/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 16:29)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_SUBTRACT_TESTING_DETAIL_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_SUBTRACT_TESTING_DETAIL_H

#include "InterlockedSubtractTesting.h"
#include "System/Threading/InterlockedDetail.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void System::InterlockedSubtractTesting::InterlockedSubtractTest()
{
    T original{ 5 };
    T value{ original };
    T add{ 10 };

    ASSERT_EQUAL(SystemInterlockedExchangeSubtract(&value, add), original);
    ASSERT_EQUAL(value, original - add);
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_SUBTRACT_TESTING_DETAIL_H