///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/20 11:39)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_COMPLETE_USE_TESTING_TYPE_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_COMPLETE_USE_TESTING_TYPE_H

#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    class UnitTestSuiteMacroCompleteUseTestingType final
    {
    public:
        using ClassType = UnitTestSuiteMacroCompleteUseTestingType;

    public:
        UnitTestSuiteMacroCompleteUseTestingType() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_USE_TESTING_TYPE_H