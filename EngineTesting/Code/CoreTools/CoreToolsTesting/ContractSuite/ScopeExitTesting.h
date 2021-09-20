///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/25 20:51)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ScopeExitTest();
        static void AddTestValue() noexcept;

    private:
        static int testValue;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_SCOPE_EXIT_TESTING_H