///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:18)

#ifndef CORE_TOOLS_HELPER_SUITE_COPY_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_COPY_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyMemberFunctionStaticAssertMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CopyMemberFunctionStaticAssertMacroTesting;
        using ParentType = UnitTest;
        using ClassShareType = DelayCopyUnsharedClasses;

    public:
        explicit CopyMemberFunctionStaticAssertMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NonConstMemberFunctionTest() noexcept;

        void Copy() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_COPY_MEMBER_FUNCTION_STATIC_ASSERT_MACRO_TESTING_H