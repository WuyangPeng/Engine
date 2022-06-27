///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:52)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class ConsoleMainFunctionHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleMainFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleMainFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConsoleMainFunctionHelper1Test();
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H