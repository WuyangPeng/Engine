///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/31 14:49)

#ifndef CORE_TOOLS_CONSOLE_SUITE_CONSOLE_COLORS_TESTING_H
#define CORE_TOOLS_CONSOLE_SUITE_CONSOLE_COLORS_TESTING_H

#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleColorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConsoleColorsTesting : public UnitTest
    {
    public:
        using ClassType = ConsoleColorsTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleColorsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void IntensifiedColorsTest();
        void BlackBackgroundColorTest();
        void ColorsTest();
        void ResetColorsTest();

        void SetColorsTest(TextColour textColor, BackgroundColour backgroundColor);
        void SetIntensifiedTextColorsTest(TextColour textColor, BackgroundColour backgroundColor);
        void SetIntensifiedBackgroundColorsTest(TextColour textColor, BackgroundColour backgroundColor);

    private:
        using OutputConsoleColors = ConsoleColors<StandardHandle::Output>;

    private:
        OutputConsoleColors console;
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_COLORS_TESTING_H