///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:51)

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
        using DesiredAccessGenericFlagsContainer = std::vector<DesiredAccessGeneric>;
        using ConsoleScreenBufferShareModeFlagsContainer = std::vector<ConsoleScreenBufferShareMode>;

    private:
        DesiredAccessGenericFlagsContainer desiredAccessGenericFlags;
        ConsoleScreenBufferShareModeFlagsContainer consoleScreenBufferShareModeFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_SCREEN_BUFFER_INFO_TESTING_H