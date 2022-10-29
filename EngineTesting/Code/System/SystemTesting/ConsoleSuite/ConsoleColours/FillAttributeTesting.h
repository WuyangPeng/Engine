///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/15 21:53)

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
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H