///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/04 22:54)

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