///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/04 22:15)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_EXCEPTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_EXCEPTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertExceptionMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AssertExceptionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertExceptionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AssertExceptionMacroTest();

        void AssertNotThrowExceptionTest() noexcept;
        void AssertNotThrowExceptionTestWithParameter(int parameter) noexcept;
        void AssertNotThrowExceptionTestWithTwoParameter(int parameter0, int parameter1) noexcept;
        void AssertThrowExceptionTest();
        void AssertThrowExceptionTestWithParameter(int parameter);
        void AssertThrowExceptionTestWithTwoParameter(int parameter0, int parameter1);
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_EXCEPTION_MACRO_TESTING_H