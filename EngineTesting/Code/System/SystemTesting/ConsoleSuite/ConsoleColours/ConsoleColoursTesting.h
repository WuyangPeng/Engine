///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/08 15:16)

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
        using TextColourFlagsDescription = std::map<TextColour, std::string>;
        using BackgroundColourFlagsDescription = std::map<BackgroundColour, std::string>;
        using ConsoleCommonFlagsDescription = std::map<ConsoleCommon, std::string>;

    private:
        TextColourFlagsDescription textColourFlagsDescription;
        BackgroundColourFlagsDescription backgroundColourFlagsDescription;
        ConsoleCommonFlagsDescription consoleCommonFlagsDescription;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING_H