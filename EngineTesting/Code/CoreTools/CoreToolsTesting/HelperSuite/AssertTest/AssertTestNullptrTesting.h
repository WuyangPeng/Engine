///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/02 19:33)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTINGG_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTINGG_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestNullptrTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertTestNullptrTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestNullptrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertNullptrTest();
        void AssertNullptrMessageTest();
        void AssertNullptrFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTINGG_H