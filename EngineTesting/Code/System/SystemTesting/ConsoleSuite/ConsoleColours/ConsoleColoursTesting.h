///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 14:07)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class ConsoleColoursTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleColoursTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleColoursTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING_H