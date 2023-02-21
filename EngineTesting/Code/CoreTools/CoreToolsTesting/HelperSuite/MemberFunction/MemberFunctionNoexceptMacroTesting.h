///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 21:05)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MemberFunctionNoexceptMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemberFunctionNoexceptMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MemberFunctionNoexceptMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConstMemberFunctionTest();
        void NonConstMemberFunctionTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_NOEXCEPT_MACRO_TESTING_H