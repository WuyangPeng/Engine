///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/16 11:42)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConsoleFontTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleFontTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleFontTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void CurrentConsoleFontTest();
        void MaximumConsoleFontTest();
        void SetCurrentConsoleFontTest();
        void CurrentConsoleFontSizeTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_FONT_TESTING_H