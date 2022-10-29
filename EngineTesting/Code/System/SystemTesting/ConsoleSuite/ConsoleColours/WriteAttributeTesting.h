///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:52)

#ifndef SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class WriteAttributeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WriteAttributeTesting;
        using ParentType = UnitTest;

    public:
        explicit WriteAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void WriteAttributeTest();

    private:
        using StandardHandleFlagsContainer = std::vector<StandardHandle>;
        using TextColourFlagsContainer = std::vector<TextColour>;
        using BackgroundColourFlagsContainer = std::vector<BackgroundColour>;
        using ConsoleCommonFlagsContainer = std::vector<ConsoleCommon>;

    private:
        StandardHandleFlagsContainer standardHandleFlags;
        TextColourFlagsContainer textColourFlags;
        BackgroundColourFlagsContainer backgroundColourFlags;
        ConsoleCommonFlagsContainer consoleCommonFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H