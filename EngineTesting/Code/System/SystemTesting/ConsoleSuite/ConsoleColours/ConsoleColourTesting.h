/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:22)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_COLOUR_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_COLOUR_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class ConsoleColourTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleColourTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleColourTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void PrintMessage(StandardHandle standardHandle, TextColour textColour, BackgroundColour backgroundColour, ConsoleCommon consoleCommon) const;

    private:
        using TextColourContainer = std::map<TextColour, std::string>;
        using BackgroundColourContainer = std::map<BackgroundColour, std::string>;
        using ConsoleCommonContainer = std::map<ConsoleCommon, std::string>;

    private:
        TextColourContainer textColourDescription;
        BackgroundColourContainer backgroundColourDescription;
        ConsoleCommonContainer consoleCommonDescription;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOUR_TESTING_H