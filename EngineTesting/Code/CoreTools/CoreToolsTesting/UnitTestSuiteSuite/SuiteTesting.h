///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:27)

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