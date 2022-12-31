///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/06 16:03)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H

#include "ConsoleScreenBufferTesting.h"
#include "System/Console/Using/ConsoleScreenBufferUsing.h"

namespace System
{
    class ConsoleScreenBufferInfoTesting final : public ConsoleScreenBufferTesting
    {
    public:
        using ClassType = ConsoleScreenBufferInfoTesting;
        using ParentType = ConsoleScreenBufferTesting;

    public:
        explicit ConsoleScreenBufferInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ConsoleScreenBufferInfoTest();

        void DoConsoleScreenBufferInfoTest(size_t index);
        void GetSystemConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle);
        void EqualTest(const ConsoleScreenBufferInfo& consoleScreenBufferInfo, const ConsoleScreenBufferInfoEx& consoleScreenBufferInfoEx);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H