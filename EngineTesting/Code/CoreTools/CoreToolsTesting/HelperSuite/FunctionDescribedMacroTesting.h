///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/29 19:07)

#ifndef CORE_TOOLS_HELPER_SUITE_FUNCTION_DESCRIBED_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_FUNCTION_DESCRIBED_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FunctionDescribedMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FunctionDescribedMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit FunctionDescribedMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FunctionDescribedTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_FUNCTION_DESCRIBED_MACRO_TESTING_H