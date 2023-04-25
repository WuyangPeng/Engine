///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:50)

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