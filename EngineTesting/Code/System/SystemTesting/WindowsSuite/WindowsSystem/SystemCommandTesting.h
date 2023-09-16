///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:40)

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
        void DoRunUnitTest() override;
        void MainTest();

        void SystemCommandTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_SYSTEM_COMMAND_TESTING_H