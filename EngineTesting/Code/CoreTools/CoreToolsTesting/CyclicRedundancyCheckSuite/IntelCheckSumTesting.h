///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:11)

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
