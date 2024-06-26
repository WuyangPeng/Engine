/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

#ifndef SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void SetConsoleScreenBufferSizeTest(WindowsHandle attributesConsoleHandle);
        void DoSetConsoleScreenBufferSizeTest(WindowsHandle attributesConsoleHandle);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_SET_SYSTEM_CONSOLE_SCREEN_BUFFER_SIZE_TESTING_H