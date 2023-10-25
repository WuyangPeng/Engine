///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:59)

#ifndef CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_DETAIL_H

#include "ModuleExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::ModuleExportMacroTesting::ModuleExportTest()
{
    constexpr auto count = 10;
    T macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);

    macro.SetCount(0);

    ASSERT_EQUAL(macro.GetCount(), 0);
}

#endif  // CORE_TOOLS_HELPER_SUITE_MODULE_EXPORT_MACRO_TESTING_DETAIL_H