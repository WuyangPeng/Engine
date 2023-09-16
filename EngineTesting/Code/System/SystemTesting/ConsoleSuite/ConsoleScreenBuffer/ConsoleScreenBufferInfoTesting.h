///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:30)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ConsoleScreenBufferInfoTest();

        void DoConsoleScreenBufferInfoTest(size_t index);
        void GetSystemConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle);
        void EqualTest(const ConsoleScreenBufferInfo& consoleScreenBufferInfo, const ConsoleScreenBufferInfoEx& consoleScreenBufferInfoEx);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H