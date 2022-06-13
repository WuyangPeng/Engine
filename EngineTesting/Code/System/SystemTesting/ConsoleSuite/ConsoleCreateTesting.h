///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:02)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConsoleCreateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleCreateTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleCreateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetSystemConsoleWindowTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H