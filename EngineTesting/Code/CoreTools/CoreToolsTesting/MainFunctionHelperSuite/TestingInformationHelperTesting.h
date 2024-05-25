/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:51)

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
        void DoRunUnitTest() override;
        void MainTest();

        void InformationTest();
        void SuiteExceptionTest();
        void TestingExceptionTest();
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H