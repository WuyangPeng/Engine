/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/05 23:15)

#ifndef CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_DETAIL_H

#include "CopyModuleExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::CopyModuleExportMacroTesting::CopyModuleExportTest()
{
    T original{ count };

    auto copy = original;
    CountTest(original, copy, count, count);

    original.SetCount(0);
    CountTest(original, copy, 0, count);

    copy.SetCount(1);
    CountTest(original, copy, 0, 1);
}

template <typename T>
void CoreTools::CopyModuleExportMacroTesting::CountTest(const T& lhs, const T& rhs, int lhsCount, int rhsCount)
{
    ASSERT_EQUAL(lhs.GetCount(), lhsCount);
    ASSERT_EQUAL(rhs.GetCount(), rhsCount);
}

#endif  // CORE_TOOLS_HELPER_SUITE_COPY_MODULE_EXPORT_MACRO_TESTING_DETAIL_H
