///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 10:52)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class ConsoleMainFunctionHelperBaseTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleMainFunctionHelperBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleMainFunctionHelperBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void ConsoleMainFunctionHelperBase1Test();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H