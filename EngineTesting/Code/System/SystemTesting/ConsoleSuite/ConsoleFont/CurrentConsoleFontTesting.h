///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/04 20:29)

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