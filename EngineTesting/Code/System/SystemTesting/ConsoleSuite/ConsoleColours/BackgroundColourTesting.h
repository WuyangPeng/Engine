///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/08 18:26)

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
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using BackgroundColourFlagsCollection = std::vector<BackgroundColour>;
        using BackgroundColourFlagsMapping = std::map<BackgroundColour, TextColour>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
        BackgroundColourFlagsCollection backgroundColourFlags;
        BackgroundColourFlagsMapping backgroundColourFlagsMapping;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_BACKGROUND_COLOUR_TESTING_H