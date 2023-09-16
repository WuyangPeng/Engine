///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:30)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_SIZE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConsoleFontSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleFontSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleFontSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void CurrentConsoleFontSizeTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_SIZE_TESTING_H