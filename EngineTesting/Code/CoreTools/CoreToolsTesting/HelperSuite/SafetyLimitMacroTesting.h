/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 12:07)

#ifndef CORE_TOOLS_HELPER_SUITE_SAFETY_LIMIT_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_SAFETY_LIMIT_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SafetyLimitMacroTesting final : public UnitTest
    {
    public:
        using ClassType = SafetyLimitMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SafetyLimitMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MacroTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SAFETY_LIMIT_MACRO_TESTING_H