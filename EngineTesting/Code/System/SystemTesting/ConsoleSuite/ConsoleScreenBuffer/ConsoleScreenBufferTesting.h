///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:30)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class ConsoleScreenBufferTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleScreenBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleScreenBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void RandomShuffleConsoleFlags();
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD DesiredAccessGeneric GetDesiredAccessGeneric(size_t index) const;
        NODISCARD ConsoleScreenBufferShareMode GetConsoleScreenBufferShareMode(size_t index) const;

    private:
        using DesiredAccessGenericContainer = std::vector<DesiredAccessGeneric>;
        using ConsoleScreenBufferShareModeContainer = std::vector<ConsoleScreenBufferShareMode>;

    private:
        DesiredAccessGenericContainer desiredAccessGenerics;
        ConsoleScreenBufferShareModeContainer consoleScreenBufferShareModes;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_TESTING_H