/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:08)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace CoreTools
{
    class SpecifyCheckSumTesting final : public UnitTest
    {
    public:
        using ClassType = SpecifyCheckSumTesting;
        using ParentType = UnitTest;

    public:
        explicit SpecifyCheckSumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr std::array buffer{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SumTest();

        void SevenTest();
        void Nine0Test();
        void Nine1Test();
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
