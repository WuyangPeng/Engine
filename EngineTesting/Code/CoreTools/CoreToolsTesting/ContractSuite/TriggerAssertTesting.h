///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/25 21:04)

#ifndef CORE_TOOLS_CONTRACT_SUITE_TRIGGER_ASSERT_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_TRIGGER_ASSERT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TriggerAssertTesting final : public UnitTest
    {
    public:
        using ClassType = TriggerAssertTesting;
        using ParentType = UnitTest;

    public:
        explicit TriggerAssertTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TriggerInvariantTest();
        void TriggerAssertionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_TRIGGER_ASSERT_TESTING_H