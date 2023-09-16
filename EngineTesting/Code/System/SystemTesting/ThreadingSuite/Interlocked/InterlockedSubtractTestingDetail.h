///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:19)

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