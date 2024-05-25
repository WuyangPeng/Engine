/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 20:31)

#ifndef CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MemberFunctionStaticAssertMacroTesting final : public UnitTest
    {
    public:
        using ClassType = MemberFunctionStaticAssertMacroTesting;
        using ParentType = UnitTest;

        using ClassShareType = CopyUnsharedClasses;

    public:
        explicit MemberFunctionStaticAssertMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NonConstMemberFunctionTest() noexcept;
        void ConstructorFunctionTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H