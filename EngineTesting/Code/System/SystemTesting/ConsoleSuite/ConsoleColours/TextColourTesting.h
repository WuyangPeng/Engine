/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:23)

#ifndef SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H
#define SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H

#include "ConsoleStandardHandlesTesting.h"

namespace System
{
    class TextColourTesting final : public ConsoleStandardHandlesTesting
    {
    public:
        using ClassType = TextColourTesting;
        using ParentType = ConsoleStandardHandlesTesting;

    public:
        explicit TextColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void TextColourTest();
        void DoTextColourTest(size_t index);

    private:
        using TextColourContainer = std::vector<TextColour>;
        using TextColourMapping = std::map<TextColour, BackgroundColour>;

    private:
        TextColourContainer textColourContainer;
        TextColourMapping textColourMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_TEXT_COLOUR_TESTING_H