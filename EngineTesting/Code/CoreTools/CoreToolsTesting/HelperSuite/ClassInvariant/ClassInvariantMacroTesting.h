///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:51)

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
        void DoRunUnitTest() override;
        void MainTest();

        void StubMacroTest() noexcept;
        void LevelTest();
        void ValidTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_CLASS_INVARIANT_MACRO_TESTING_H