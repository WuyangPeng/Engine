///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:05)

#ifndef FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class MainFunctionEntryPointTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MainFunctionEntryPointTesting;
        using ParentType = UnitTest;

    public:
        explicit MainFunctionEntryPointTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void WinMainEntryPoint1Test();
        void WinMainEntryPoint2Test();
        void MainEntryPoint1Test();
        void GlutMainEntryPoint1Test();
        void AndroidMainEntryPoint1Test();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H