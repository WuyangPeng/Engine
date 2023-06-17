///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:14)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

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