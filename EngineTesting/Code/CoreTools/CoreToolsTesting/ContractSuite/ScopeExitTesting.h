///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:28)

#ifndef CORE_TOOLS_CONTRACT_SUITE_SCOPE_EXIT_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_SCOPE_EXIT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ScopeExitTesting final : public UnitTest
    {
    public:
        using ClassType = ScopeExitTesting;
        using ParentType = UnitTest;

    public:
        explicit ScopeExitTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using FunctionType = void (*)();

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ScopeExitTest();
        static void AddTestValue() noexcept;

    private:
        static int testValue;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_SCOPE_EXIT_TESTING_H