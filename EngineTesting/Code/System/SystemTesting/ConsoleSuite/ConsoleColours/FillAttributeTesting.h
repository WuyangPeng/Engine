///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:01)

#ifndef SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class FillAttributeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FillAttributeTesting;
        using ParentType = UnitTest;

    public:
        explicit FillAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FillAttributeTest();

    private:
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using TextColourFlagsCollection = std::vector<TextColour>;
        using BackgroundColourFlagsCollection = std::vector<BackgroundColour>;
        using ConsoleCommonFlagsCollection = std::vector<ConsoleCommon>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
        TextColourFlagsCollection textColourFlags;
        BackgroundColourFlagsCollection backgroundColourFlags;
        ConsoleCommonFlagsCollection consoleCommonFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H