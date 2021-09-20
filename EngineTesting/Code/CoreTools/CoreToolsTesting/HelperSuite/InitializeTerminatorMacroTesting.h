///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/15 11:03)

#ifndef CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class InitializeTerminatorMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitializeTerminatorMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeTerminatorMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InitTermTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_INIT_TERM_MACRO_TESTING_H