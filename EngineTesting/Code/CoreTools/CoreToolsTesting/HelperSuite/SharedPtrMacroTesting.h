/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 11:40)

#ifndef CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedPtrMacroTesting final : public UnitTest
    {
    public:
        using ClassType = SharedPtrMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SharedPtrMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MacroTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H