///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 18:55)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CMainFunctionTestingHelperTesting : public UnitTest
    {
    public:
        using ClassType = CMainFunctionTestingHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit CMainFunctionTestingHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H