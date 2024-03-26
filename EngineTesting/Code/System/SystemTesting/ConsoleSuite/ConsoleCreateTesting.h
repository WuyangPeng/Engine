/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// ConsoleCreate的单元测试使用ConsoleSystemTesting进行。
    class ConsoleCreateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleCreateTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleCreateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetSystemConsoleWindowTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_CREATE_TESTING_H