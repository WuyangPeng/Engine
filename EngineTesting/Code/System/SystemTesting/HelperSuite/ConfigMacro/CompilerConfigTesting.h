///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:27)

#ifndef SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CompilerConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CompilerConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit CompilerConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CompilerTest();
        void VisualCTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_COMPILER_CONFIG_TESTING_H
