/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:50)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// CMainFunctionHelperʹ��Toolset�е�CMainFunctionHelper���ԡ�
    /// �����ǿղ��ԡ�
    class CMainFunctionHelperTesting final : public UnitTest
    {
    public:
        using ClassType = CMainFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit CMainFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_HELPER_TESTING_H