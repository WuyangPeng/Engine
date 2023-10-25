///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:50)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SpecifyCheckSumTesting : public UnitTest
    {
    public:
        using ClassType = SpecifyCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit SpecifyCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void SumTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
