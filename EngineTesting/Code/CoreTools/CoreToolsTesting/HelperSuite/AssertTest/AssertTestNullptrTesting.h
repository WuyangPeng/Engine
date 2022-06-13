///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:12)

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