///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/09 16:04)

#ifndef SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <set>
#include <vector>

namespace System
{
    class ReadAttributeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReadAttributeTesting;
        using ParentType = UnitTest;

    public:
        explicit ReadAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ReadAttributeTest();

    private:
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using TextColourFlagsCollection = std::set<TextColour>;
        using BackgroundColourFlagsCollection = std::set<BackgroundColour>;
        using ConsoleCommonFlagsCollection = std::set<ConsoleCommon>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
        TextColourFlagsCollection textColourFlags;
        BackgroundColourFlagsCollection backgroundColourFlags;
        ConsoleCommonFlagsCollection consoleCommonFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H