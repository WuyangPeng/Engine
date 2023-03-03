///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/06 11:25)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_OPERATOR_TESTINGG_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_OPERATOR_TESTINGG_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestOperatorTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestOperatorTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestOperatorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertOperatorTest();
        void AssertOperatorMessageTest();
        void AssertOperatorFailureThrowTest();
        void AssertOperatorDoNotUseMessageTest();
        void AssertOperatorDoNotUseMessageFailureThrowTest();
        void AssertEnumOperatorTest();
        void AssertEnumOperatorMessageTest();
        void AssertEnumOperatorFailureThrowTest();
        void AssertSignedEnumOperatorTest();
        void AssertSignedEnumOperatorMessageTest();
        void AssertSignedEnumOperatorFailureThrowTest();
        void AssertThreeOperatorTest();
        void AssertThreeOperatorMessageTest();
        void AssertThreeOperatorFailureThrowTest();
        void AssertFloatingPointCompleteOperatorTest();
        void AssertFloatingPointCompleteOperatorMessageTest();
        void AssertFloatingPointCompleteOperatorFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_OPERATOR_TESTINGG_H