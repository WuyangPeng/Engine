///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:51)

#ifndef C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H
#define C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CMainFunctionHelper
{
    class UnitTestHelper final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UnitTestHelper;
        using ParentType = UnitTest;

    public:
        explicit UnitTestHelper(bool isCout);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() noexcept override;
    };
}

#endif  // C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H