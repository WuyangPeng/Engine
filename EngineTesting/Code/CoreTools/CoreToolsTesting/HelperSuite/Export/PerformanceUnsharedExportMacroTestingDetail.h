///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 16:00)

#ifndef CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H

#include "PerformanceUnsharedExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::PerformanceUnsharedExportMacroTesting::PerformanceUnsharedExportTest()
{
    constexpr auto count = 10;
    T original{ count };

    auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
    ASSERT_EQUAL(copy.GetAddress(), original.GetAddress());
}

#endif  // CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H