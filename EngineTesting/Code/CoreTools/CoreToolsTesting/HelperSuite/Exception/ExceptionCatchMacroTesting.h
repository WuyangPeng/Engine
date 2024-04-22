/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 11:41)

#ifndef CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ExceptionCatchMacroTesting final : public UnitTest
    {
    public:
        using ClassType = ExceptionCatchMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExceptionCatchMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Catch0Test();
        void Catch1Test();
        void Catch2Test();
        void Catch3Test();

        void PrintTipsMessage() override;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H