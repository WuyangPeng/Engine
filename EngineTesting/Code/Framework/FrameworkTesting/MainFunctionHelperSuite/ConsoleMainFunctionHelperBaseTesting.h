///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:14)

#ifndef FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H
#define FRAMEWORK_HELPER_SUITE_CONSOLE_MAIN_FUNCTION_HELPER_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

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