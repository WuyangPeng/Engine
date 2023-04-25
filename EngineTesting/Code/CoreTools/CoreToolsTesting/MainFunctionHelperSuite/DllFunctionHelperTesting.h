///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/13 11:19)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DllFunctionHelperTesting final : public UnitTest
    {
    public:
        using ClassType = DllFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit DllFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DllMutexTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H