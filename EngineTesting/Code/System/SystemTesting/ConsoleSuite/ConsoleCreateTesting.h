///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/17 22:55)

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