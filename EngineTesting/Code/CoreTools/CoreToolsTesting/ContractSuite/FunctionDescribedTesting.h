///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/25 18:24)

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