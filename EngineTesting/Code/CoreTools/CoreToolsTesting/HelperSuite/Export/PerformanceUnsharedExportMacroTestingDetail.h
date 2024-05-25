/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/06 19:18)

#ifndef CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H

#include "PerformanceUnsharedExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::PerformanceUnsharedExportMacroTesting::PerformanceUnsharedExportTest()
{
    T original{ count };

    auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
    ASSERT_EQUAL(copy.GetAddress(), original.GetAddress());
}

#endif  // CORE_TOOLS_HELPER_SUITE_PERFORMANCE_UNSHARED_EXPORT_MACRO_TESTING_DETAIL_H