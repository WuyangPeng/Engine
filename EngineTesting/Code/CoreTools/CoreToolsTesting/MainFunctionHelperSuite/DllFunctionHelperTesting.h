/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:51)

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
        void DoRunUnitTest() override;
        void MainTest();

        void DllMutexTest();
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H