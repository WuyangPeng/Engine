///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:52)

#ifndef SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H
#define SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H

#include "ConsoleColoursTesting.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class TextColourTesting final : public ConsoleColoursTesting
    {
    public:
        using ClassType = TextColourTesting;
        using ParentType = ConsoleColoursTesting;

    public:
        explicit TextColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void TextColourTest();
        void SetDefaultTextAttribute();

    private:
        using StandardHandleFlagsContainer = std::vector<StandardHandle>;
        using TextColourFlagsContainer = std::vector<TextColour>;
        using TextColourFlagsMapping = std::map<TextColour, BackgroundColour>;

    private:
        StandardHandleFlagsContainer standardHandleFlags;
        TextColourFlagsContainer textColourFlags;
        TextColourFlagsMapping textColourFlagsMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H