///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 19:01)

#ifndef SYSTEM_WINDOWS_SUITE_SYSTEM_COMMAND_TESTING_H
#define SYSTEM_WINDOWS_SUITE_SYSTEM_COMMAND_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SystemCommandTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SystemCommandTesting;
        using ParentType = UnitTest;

    public:
        explicit SystemCommandTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SystemCommandTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_SYSTEM_COMMAND_TESTING_H