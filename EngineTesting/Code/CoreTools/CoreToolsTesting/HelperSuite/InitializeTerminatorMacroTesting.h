///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:23)

#ifndef CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InitializeTerminatorMacroTesting final : public UnitTest
    {
    public:
        using ClassType = InitializeTerminatorMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeTerminatorMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitTermTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H