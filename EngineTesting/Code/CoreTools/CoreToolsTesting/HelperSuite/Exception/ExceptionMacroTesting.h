///	Copyright (c) 2010-2022
///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/18 10:50)

#ifndef CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ExceptionMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ExceptionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExceptionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThrowErrorTest();
        void ThrowWindowsErrorTest();
        void ThrowComErrorTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H