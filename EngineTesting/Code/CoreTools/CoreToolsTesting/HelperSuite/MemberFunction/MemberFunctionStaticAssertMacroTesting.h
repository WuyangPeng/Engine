///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:18)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MemberFunctionStaticAssertMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MemberFunctionStaticAssertMacroTesting;
        using ParentType = UnitTest;
        using ClassShareType = CopyUnsharedClasses;

    public:
        explicit MemberFunctionStaticAssertMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NonConstMemberFunctionTest() noexcept;
        void ConstructorFunctionTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H