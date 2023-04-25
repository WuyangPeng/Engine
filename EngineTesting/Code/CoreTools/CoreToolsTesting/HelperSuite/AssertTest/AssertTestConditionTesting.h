///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:51)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestConditionTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestConditionTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestConditionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertConditionTest();
        void AssertConditionMessageTest();
        void AssertConditionFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H