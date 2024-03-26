/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:53)

#ifndef SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_DETAIL_H
#define SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_DETAIL_H

#include "FixedSizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void System::FixedSizeTesting::DoIntegerMinCriticalTest(T oldValue, T newValue)
{
    auto test = oldValue;
    --test;
    ASSERT_EQUAL(test, newValue);
}

template <typename T>
void System::FixedSizeTesting::DoIntegerMaxCriticalTest(T oldValue, T newValue)
{
    auto test = oldValue;
    ++test;
    ASSERT_EQUAL(test, newValue);
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_FIXED_SIZE_TESTING_DETAIL_H
