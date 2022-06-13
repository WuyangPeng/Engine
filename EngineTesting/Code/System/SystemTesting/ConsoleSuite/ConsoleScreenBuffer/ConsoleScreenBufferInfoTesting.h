///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:02)

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