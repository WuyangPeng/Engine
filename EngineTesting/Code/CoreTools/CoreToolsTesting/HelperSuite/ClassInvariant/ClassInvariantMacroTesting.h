///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:13)

#ifndef CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ClassInvariantMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ClassInvariantMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ClassInvariantMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StubMacroTest() noexcept;
        void LevelTest();
        void ValidTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_MACRO_TESTING_H