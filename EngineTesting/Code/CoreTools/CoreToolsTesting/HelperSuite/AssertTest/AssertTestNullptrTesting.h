/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 21:30)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertTestNullptrTesting final : public UnitTest
    {
    public:
        using ClassType = AssertTestNullptrTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertTestNullptrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertNullptrTest();
        void AssertNullptrMessageTest();
        void AssertNullptrFailureThrowTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_TEST_NULLPTR_TESTING_H