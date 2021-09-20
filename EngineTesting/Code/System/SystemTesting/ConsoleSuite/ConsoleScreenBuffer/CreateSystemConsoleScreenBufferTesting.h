///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/08 18:26)

#ifndef SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateSystemConsoleScreenBufferTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateSystemConsoleScreenBufferTesting;
        using ParentType = UnitTest;

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

    private:
        using DesiredAccessGenericFlagsCollection = std::vector<DesiredAccessGeneric>;
        using ConsoleScreenBufferShareModeFlagsCollection = std::vector<ConsoleScreenBufferShareMode>;

    private:
        DesiredAccessGenericFlagsCollection desiredAccessGenericFlags;
        ConsoleScreenBufferShareModeFlagsCollection consoleScreenBufferShareModeFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CREATE_SYSTEM_CONSOLE_SCREEN_BUFFER_TESTING_H