///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:56)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_ADD_TEST_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_ADD_TEST_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UnitTestSuiteAddTestMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UnitTestSuiteAddTestMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream);
        UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream, bool isPrintRun);
        UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream, bool isPrintRun, int count);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;

    private:
        bool isPrintRun;
        int count;
    };

}

#endif  // CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_ADD_TEST_MACRO_TESTING_H