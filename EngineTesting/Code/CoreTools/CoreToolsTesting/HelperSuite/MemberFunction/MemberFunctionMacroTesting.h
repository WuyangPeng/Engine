///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/12 21:05)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MemberFunctionMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemberFunctionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit MemberFunctionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConstMemberFunctionTest();
        void NonConstMemberFunctionTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_MACRO_TESTING_H