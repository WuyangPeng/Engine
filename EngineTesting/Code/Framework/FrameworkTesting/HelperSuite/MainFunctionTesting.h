///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:05)

#ifndef FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

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