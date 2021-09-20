///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 11:40)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_COMPLETE_USE_TESTING_TYPE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_COMPLETE_USE_TESTING_TYPE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class UnitTestSuiteMacroCompleteUseTestingTypeTesting final : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UnitTestSuiteMacroCompleteUseTestingTypeTesting);

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TypedefTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_COMPLETE_USE_TESTING_TYPE_TESTING_H