///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/13 11:18)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CMainFunctionHelperTesting final : public UnitTest
    {
    public:
        using ClassType = CMainFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit CMainFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H