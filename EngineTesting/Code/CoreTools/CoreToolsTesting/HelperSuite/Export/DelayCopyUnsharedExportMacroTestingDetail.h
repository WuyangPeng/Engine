/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/05 23:15)

#ifndef CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H

#include "DelayCopyUnsharedExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::DelayCopyUnsharedExportMacroTesting::DelayCopyUnsharedExportTest()
{
    T original{ count };

    auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
    ASSERT_EQUAL(copy.GetAddress(), original.GetAddress());

    original.SetCount(0);
    CountTest(original, copy, 0, count);

    copy.SetCount(1);
    CountTest(original, copy, 0, 1);
}

template <typename T>
void CoreTools::DelayCopyUnsharedExportMacroTesting::CountTest(const T& lhs, const T& rhs, int lhsCount, int rhsCount)
{
    ASSERT_EQUAL(lhs.GetCount(), lhsCount);
    ASSERT_EQUAL(rhs.GetCount(), rhsCount);
    ASSERT_UNEQUAL(lhs.GetAddress(), rhs.GetAddress());
}

#endif  // CORE_TOOLS_HELPER_SUITE_DELAY_COPY_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H
