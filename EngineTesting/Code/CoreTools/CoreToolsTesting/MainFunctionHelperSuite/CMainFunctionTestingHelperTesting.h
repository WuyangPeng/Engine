///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:38)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CMainFunctionTestingHelperTesting final : public UnitTest
    {
    public:
        using ClassType = CMainFunctionTestingHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit CMainFunctionTestingHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_C_MAIN_FUNCTION_TESTING_HELPER_TESTING_H