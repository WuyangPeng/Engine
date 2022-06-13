///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:30)

#ifndef CORE_TOOLS_CONTRACT_SUITE_FUNCTION_DESCRIBED_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_FUNCTION_DESCRIBED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FunctionDescribedTesting final : public UnitTest
    {
    public:
        using ClassType = FunctionDescribedTesting;
        using ParentType = UnitTest;

    public:
        explicit FunctionDescribedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FunctionDescribedTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_FUNCTION_DESCRIBED_TESTING_H