///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 14:17)

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
        void DoRunUnitTest() override;
        void MainTest();

        void FunctionDescribedTest() noexcept;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_FUNCTION_DESCRIBED_TESTING_H