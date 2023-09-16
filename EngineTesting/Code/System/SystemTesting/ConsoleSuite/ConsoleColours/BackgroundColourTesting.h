///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:27)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void BackgroundColourTest();

        void DoBackgroundColourTest(size_t index);

    private:
        using BackgroundColourContainer = std::vector<BackgroundColour>;
        using BackgroundColourMapping = std::map<BackgroundColour, TextColour>;

    private:
        BackgroundColourContainer backgroundColourContainer;
        BackgroundColourMapping backgroundColourMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H