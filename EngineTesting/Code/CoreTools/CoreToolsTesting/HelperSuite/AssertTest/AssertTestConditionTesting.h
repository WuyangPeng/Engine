///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/02 16:43)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestConditionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestConditionTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestConditionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertConditionTest();
        void AssertConditionMessageTest();
        void AssertConditionFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_CONDITION_TESTING_H