///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:50)

#ifndef CORE_TOOLS_HELPER_SUITE_ASSERT_EXECUTE_LOOP_NOT_THROW_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_ASSERT_EXECUTE_LOOP_NOT_THROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertExecuteLoopNotThrowTesting final : public UnitTest
    {
    public:
        using ClassType = AssertExecuteLoopNotThrowTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertExecuteLoopNotThrowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertExceptionMacroTest();

        NODISCARD bool ExecuteLoopNotThrowTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_ASSERT_EXECUTE_LOOP_NOT_THROW_TESTING_H