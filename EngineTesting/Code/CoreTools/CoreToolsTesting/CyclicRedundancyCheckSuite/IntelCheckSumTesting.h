///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:04)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class IntelCheckSumTesting : public UnitTest
    {
    public:
        using ClassType = IntelCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit IntelCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void SumTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_INTEL_CHECK_SUM_TESTING_H
