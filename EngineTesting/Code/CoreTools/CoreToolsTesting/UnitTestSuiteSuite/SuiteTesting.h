///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/25 17:10)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SuiteTesting final : public UnitTest
    {
    public:
        using ClassType = SuiteTesting;
        using ParentType = UnitTest;

    public:
        explicit SuiteTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void NameTest();
        void StreamTest();
        void AddTestTest();
        void AddSuiteTest();
        void TestDataTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H