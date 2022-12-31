///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/06 18:19)

#ifndef SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H

#include "ConsoleScreenBufferTesting.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    class CreateSystemConsoleScreenBufferTesting final : public ConsoleScreenBufferTesting
    {
    public:
        using ClassType = CreateSystemConsoleScreenBufferTesting;
        using ParentType = ConsoleScreenBufferTesting;

    public:
        explicit CreateSystemConsoleScreenBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateNullSecurityAttributesConsoleScreenBufferTest();
        void CreateBInheritHandleTrueConsoleScreenBufferTest();
        void CreateBInheritHandleFalseConsoleScreenBufferTest();

        void CreateSystemConsoleScreenBufferTest(const WindowSecurityAttributes* securityAttributes);
        void DoCreateSystemConsoleScreenBufferTest(size_t index, const WindowSecurityAttributes* securityAttributes);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H