/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:24)

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