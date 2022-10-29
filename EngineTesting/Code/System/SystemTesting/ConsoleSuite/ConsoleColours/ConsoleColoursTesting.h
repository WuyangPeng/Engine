///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:54)

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
        void PrintMessage(StandardHandle standardHandleFlag, TextColour textColourFlag, BackgroundColour backgroundColourFlag, ConsoleCommon consoleCommonFlag);

    private:
        using TextColourFlagsContainer = std::map<TextColour, std::string>;
        using BackgroundColourFlagsContainer = std::map<BackgroundColour, std::string>;
        using ConsoleCommonFlagsContainer = std::map<ConsoleCommon, std::string>;

    private:
        TextColourFlagsContainer textColourFlagsDescription;
        BackgroundColourFlagsContainer backgroundColourFlagsDescription;
        ConsoleCommonFlagsContainer consoleCommonFlagsDescription;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING_H