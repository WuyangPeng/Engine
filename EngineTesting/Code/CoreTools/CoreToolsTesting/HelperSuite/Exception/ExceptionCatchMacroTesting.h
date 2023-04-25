///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:56)

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