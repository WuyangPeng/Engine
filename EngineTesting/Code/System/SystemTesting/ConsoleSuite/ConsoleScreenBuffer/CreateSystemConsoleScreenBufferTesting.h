/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

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
        void DoRunUnitTest() override;
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