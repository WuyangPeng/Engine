///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 11:51)

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