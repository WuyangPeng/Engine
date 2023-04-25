///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:19)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TestingInformationHelperTesting final : public UnitTest
    {
    public:
        using ClassType = TestingInformationHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit TestingInformationHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InformationTest();
        void SuiteExceptionTest();
        void TestingExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H