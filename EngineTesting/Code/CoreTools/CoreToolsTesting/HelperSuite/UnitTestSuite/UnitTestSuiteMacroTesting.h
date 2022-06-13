///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:19)

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