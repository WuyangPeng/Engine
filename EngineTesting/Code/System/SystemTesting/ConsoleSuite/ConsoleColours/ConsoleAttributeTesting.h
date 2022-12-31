///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 20:36)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_ATTRIBUTE_TESTING_H

#include "ConsoleStandardHandlesTesting.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <array>

namespace System
{
    class ConsoleAttributeTesting : public ConsoleStandardHandlesTesting
    {
    public:
        using ClassType = ConsoleAttributeTesting;
        using ParentType = ConsoleStandardHandlesTesting;

    public:
        explicit ConsoleAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 512u;
        using AttributeType = std::array<WindowsWord, bufferSize>;
        static constexpr auto textColourMask = 0x000F;
        static constexpr auto backgroundColourMask = 0x00F0;
        static constexpr auto consoleCommonMask = 0xFF00;

    protected:
        void RandomShuffleConsoleFlags();
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD TextColour GetTextColour(size_t index) const;
        NODISCARD BackgroundColour GetBackgroundColour(size_t index) const;
        NODISCARD ConsoleCommon GetConsoleCommon(size_t index) const;

        NODISCARD bool HasTextColour(TextColour textColour) const;
        NODISCARD bool HasBackgroundColour(BackgroundColour backgroundColour) const;
        NODISCARD bool HasConsoleCommon(ConsoleCommon consoleCommon) const;

        void ColourEqualTest(WindowsWord readAttribute, WindowsWord writeAttribute, int mask);

    private:
        using TextColourContainer = std::vector<TextColour>;
        using BackgroundColourContainer = std::vector<BackgroundColour>;
        using ConsoleCommonContainer = std::vector<ConsoleCommon>;

    private:
        TextColourContainer textColours;
        BackgroundColourContainer backgroundColours;
        ConsoleCommonContainer consoleCommons;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_ATTRIBUTE_TESTING_H