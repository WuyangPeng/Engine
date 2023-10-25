///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:31)

#ifndef CORE_TOOLS_CONSOLE_SUITE_CONSOLE_COLORS_TESTING_H
#define CORE_TOOLS_CONSOLE_SUITE_CONSOLE_COLORS_TESTING_H

#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Console/ConsoleColorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConsoleColorsTesting final : public UnitTest
    {
    public:
        using ClassType = ConsoleColorsTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleColorsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
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