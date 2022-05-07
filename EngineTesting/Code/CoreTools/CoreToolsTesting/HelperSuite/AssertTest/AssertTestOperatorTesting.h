///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/02 19:33)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_OPERATOR_TESTINGG_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_OPERATOR_TESTINGG_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestOperatorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestOperatorTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestOperatorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
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