/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 09:50)

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