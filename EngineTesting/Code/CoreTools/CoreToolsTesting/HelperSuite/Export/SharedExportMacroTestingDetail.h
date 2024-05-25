/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:20)

#ifndef CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_DETAIL_H

#include "SharedExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::SharedExportMacroTesting::SharedExportTest()
{
    T original{ count };

    auto copy = original;
    CountTest(original, copy, count, count);

    original.SetCount(0);
    CountTest(original, copy, 0, 0);

    copy.SetCount(1);
    CountTest(original, copy, 1, 1);
}

template <typename T>
void CoreTools::SharedExportMacroTesting::CountTest(const T& lhs, const T& rhs, int lhsCount, int rhsCount)
{
    ASSERT_EQUAL(lhs.GetCount(), lhsCount);
    ASSERT_EQUAL(rhs.GetCount(), rhsCount);
    ASSERT_EQUAL(lhs.GetAddress(), rhs.GetAddress());
}

#endif  // CORE_TOOLS_HELPER_SUITE_SHARED_EXPORT_MACRO_TESTING_DETAIL_H