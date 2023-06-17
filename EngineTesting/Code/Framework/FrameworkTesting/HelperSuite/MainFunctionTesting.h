///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:18)

#ifndef FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class MainFunctionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MainFunctionTesting;
        using ParentType = UnitTest;

    public:
        explicit MainFunctionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void WinMainEntryPoint3Test();
        void WinMainEntryPoint4Test();
        void MainEntryPoint2Test();
        void GlutMainEntryPoint2Test();
        void AndroidMainEntryPoint2Test();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H