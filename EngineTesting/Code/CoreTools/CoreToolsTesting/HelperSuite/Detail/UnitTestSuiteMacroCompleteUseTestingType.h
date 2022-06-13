///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:16)

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