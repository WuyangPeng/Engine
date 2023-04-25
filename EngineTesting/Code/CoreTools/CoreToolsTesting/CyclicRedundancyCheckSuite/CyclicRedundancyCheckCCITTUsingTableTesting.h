///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 16:02)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECKCCITT_USING_TABLE_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECKCCITT_USING_TABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CyclicRedundancyCheckCCITTUsingTableTesting final : public UnitTest
    {
    public:
        using ClassType = CyclicRedundancyCheckCCITTUsingTableTesting;
        using ParentType = UnitTest;

    public:
        explicit CyclicRedundancyCheckCCITTUsingTableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CCITTTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_CYCLIC_REDUNDANCY_CHECKCCITT_USING_TABLE_TESTING_H
