///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 1:04)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_DETAIL_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_DETAIL_H

#include "InterlockedBinaryTesting.h"
#include "System/Threading/InterlockedDetail.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void System::InterlockedBinaryTesting::InterlockedBinaryTest()
{
    T lhs{ 0xA };
    T rhs{ 0x9 };
    T result{ lhs };

    ASSERT_EQUAL(SystemInterlockedAnd(&result, rhs), lhs);
    ASSERT_EQUAL(result, static_cast<T>(0x8));

    result = lhs;

    ASSERT_EQUAL(SystemInterlockedOr(&result, rhs), lhs);
    ASSERT_EQUAL(result, static_cast<T>(0xB));

    result = lhs;

    ASSERT_EQUAL(SystemInterlockedXor(&result, rhs), lhs);
    ASSERT_EQUAL(result, static_cast<T>(0x3));
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_DETAIL_H