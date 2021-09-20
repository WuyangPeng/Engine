///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/15 13:24)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class ConsoleScreenBufferInfoTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleScreenBufferInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleScreenBufferInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ConsoleScreenBufferInfoTest();

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

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H