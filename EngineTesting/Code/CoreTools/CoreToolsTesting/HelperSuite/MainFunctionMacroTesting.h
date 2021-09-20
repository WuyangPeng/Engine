///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/15 11:12)

#ifndef CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MainFunctionMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MainFunctionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MainFunctionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MAIN_FUNCTION_MACRO_TESTING_H