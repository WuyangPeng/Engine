///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:02)

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