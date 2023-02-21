///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/18 10:41)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestSuiteMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UnitTestSuiteMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestSuiteMacroTesting(const OStreamShared& stream, bool isPrintRun);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        template <typename TestType, typename... Types>
        void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

    private:
        Suite unitTestSuiteMacroSuite;
        bool isPrintRun;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_H