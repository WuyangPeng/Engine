///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/03 18:40)

#ifndef SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H
#define SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H

#include "ConsoleStandardHandlesTesting.h"

#include <random>

namespace System
{
    class BackgroundColourTesting final : public ConsoleStandardHandlesTesting
    {
    public:
        using ClassType = BackgroundColourTesting;
        using ParentType = ConsoleStandardHandlesTesting;

    public:
        explicit BackgroundColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void BackgroundColourTest();

        void DoBackgroundColourTest(size_t index);

    private:
        using BackgroundColourContainer = std::vector<BackgroundColour>;
        using BackgroundColourMapping = std::map<BackgroundColour, TextColour>;

    private:
        BackgroundColourContainer backgroundColours;
        BackgroundColourMapping backgroundColourMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H