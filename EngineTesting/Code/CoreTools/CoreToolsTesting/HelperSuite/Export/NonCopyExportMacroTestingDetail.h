///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:50)

#ifndef CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_DETAIL_H

#include "NonCopyExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::NonCopyExportMacroTesting::NonCopyExportTest()
{
    constexpr auto count = 10;
    T macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

#endif  // CORE_TOOLS_HELPER_SUITE_NON_COPY_EXPORT_MACRO_TESTING_DETAIL_H