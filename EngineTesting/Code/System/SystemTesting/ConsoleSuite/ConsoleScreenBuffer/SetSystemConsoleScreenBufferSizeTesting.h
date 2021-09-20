///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/15 13:49)

#ifndef SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SetSystemConsoleScreenBufferSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetSystemConsoleScreenBufferSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit SetSystemConsoleScreenBufferSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetConsoleScreenBufferSizeTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H