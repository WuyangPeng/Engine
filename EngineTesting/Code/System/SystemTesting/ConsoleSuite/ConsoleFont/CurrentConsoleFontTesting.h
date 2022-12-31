///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/04 20:29)

#ifndef SYSTEM_CONSOLE_SUITE_CURRENT_CONSOLE_FONT_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CURRENT_CONSOLE_FONT_TESTING_H

#include "System/Console/Using/ConsoleFontUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CurrentConsoleFontTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CurrentConsoleFontTesting;
        using ParentType = UnitTest;

    public:
        explicit CurrentConsoleFontTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void CurrentConsoleFontTest(bool maximumWindow);

        void FontEqualTest(const ConsoleFontInfo& consoleFontInfo, const ConsoleFontInfoEx& consoleFontInfoEx);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CURRENT_CONSOLE_FONT_TESTING_H