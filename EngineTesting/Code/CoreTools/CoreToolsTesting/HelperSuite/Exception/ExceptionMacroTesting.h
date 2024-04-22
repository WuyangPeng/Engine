/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 11:41)

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
        void AssertFailThrowExceptionSuccessTest();
        void AssertFailThrowExceptionFailTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H