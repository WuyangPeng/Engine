/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:07)

#ifndef CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TESTING_H
#define CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConsoleTesting final : public UnitTest
    {
    public:
        using ClassType = ConsoleTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InputHandleTest();
        void OutputHandleTest();
        void ErrorHandleTest();
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TESTING_H
