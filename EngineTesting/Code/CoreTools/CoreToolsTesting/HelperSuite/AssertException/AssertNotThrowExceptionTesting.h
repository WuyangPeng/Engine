///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/05 21:34)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_NOT_THROW_EXCEPTION_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_NOT_THROW_EXCEPTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertNotThrowExceptionTesting final : public UnitTest
    {
    public:
        using ClassType = AssertNotThrowExceptionTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertNotThrowExceptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertExceptionMacroTest();

        void AssertNotThrowExceptionTest() noexcept;
        void AssertNotThrowExceptionTestWithParameter(int aParameter);
        void AssertNotThrowExceptionTestWith2Parameter(int aParameter0, int aParameter1);
        void AssertNotThrowExceptionTestWith3Parameter(int aParameter0, int aParameter1, int aParameter2);

    private:
        int parameter0;
        int parameter1;
        int parameter2;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_NOT_THROW_EXCEPTION_TESTING_H