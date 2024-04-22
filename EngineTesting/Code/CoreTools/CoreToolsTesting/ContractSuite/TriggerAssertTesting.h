/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 09:53)

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

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TriggerInvariantTest();
        void TriggerAssertionTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_TRIGGER_ASSERT_TESTING_H