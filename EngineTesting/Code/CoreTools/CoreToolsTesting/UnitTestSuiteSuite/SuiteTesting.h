/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:23)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/Suite.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void NameTest();
        void StreamTest();
        void AddTestTest();
        void AddSuiteTest();
        void TestDataTest();

        void AddSuite0Test(Suite& suite);
        void AddSuite1Test(const std::string& suiteName, Suite& suite0);
    };
}

#endif  // CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H