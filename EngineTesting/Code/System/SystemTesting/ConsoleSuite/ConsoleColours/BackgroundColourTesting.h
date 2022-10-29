///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/15 21:54)

#ifndef SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H
#define SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H

#include "ConsoleColoursTesting.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class BackgroundColourTesting final : public ConsoleColoursTesting
    {
    public:
        using ClassType = BackgroundColourTesting;
        using ParentType = ConsoleColoursTesting;

    public:
        explicit BackgroundColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void BackgroundColourTest();
        void SetDefaultTextAttribute();

    private:
        using StandardHandleFlagsContainer = std::vector<StandardHandle>;
        using BackgroundColourFlagsContainer = std::vector<BackgroundColour>;
        using BackgroundColourFlagsMapping = std::map<BackgroundColour, TextColour>;

    private:
        StandardHandleFlagsContainer standardHandleFlags;
        BackgroundColourFlagsContainer backgroundColourFlags;
        BackgroundColourFlagsMapping backgroundColourFlagsMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H