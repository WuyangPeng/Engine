///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:15)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_WINDOW_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_WINDOW_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowMainFunctionHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowMainFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowMainFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void WindowMainFunctionHelper1Test();
    };
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_WINDOW_MAIN_FUNCTION_HELPER_TESTING_H