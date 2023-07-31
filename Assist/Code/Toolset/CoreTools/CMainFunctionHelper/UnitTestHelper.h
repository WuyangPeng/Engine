///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:51)

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