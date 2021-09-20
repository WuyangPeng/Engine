///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 11:42)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/UnitTestSuite/Suite.h"

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