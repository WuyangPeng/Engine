/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 21:30)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_THROW_EXCEPTION_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_THROW_EXCEPTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertThrowExceptionTesting final : public UnitTest
    {
    public:
        using ClassType = AssertThrowExceptionTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertThrowExceptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertExceptionMacroTest();

        void AssertThrowExceptionTest();
        void AssertThrowExceptionTestWithParameter(int aParameter);
        void AssertThrowExceptionTestWith2Parameter(int aParameter0, int aParameter1);
        void AssertThrowExceptionTestWith3Parameter(int aParameter0, int aParameter1, int aParameter2);

    private:
        int parameter0;
        int parameter1;
        int parameter2;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_THROW_EXCEPTION_TESTING_H