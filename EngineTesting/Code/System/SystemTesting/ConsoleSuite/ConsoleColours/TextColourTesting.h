///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/08 18:26)

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
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using TextColourFlagsCollection = std::vector<TextColour>;
        using TextColourFlagsMapping = std::map<TextColour, BackgroundColour>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
        TextColourFlagsCollection textColourFlags;
        TextColourFlagsMapping textColourFlagsMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H