///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:33)

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