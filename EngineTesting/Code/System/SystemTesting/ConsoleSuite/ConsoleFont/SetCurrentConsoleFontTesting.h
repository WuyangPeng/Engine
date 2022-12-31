///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/04 14:52)

#ifndef SYSTEM_CONSOLE_SUITE_SET_CURRENT_CONSOLE_FONT_TESTING_H
#define SYSTEM_CONSOLE_SUITE_SET_CURRENT_CONSOLE_FONT_TESTING_H

#include "System/Console/Using/ConsoleFontUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SetCurrentConsoleFontTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetCurrentConsoleFontTesting;
        using ParentType = UnitTest;

    public:
        explicit SetCurrentConsoleFontTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void SetCurrentConsoleFontTest(WindowsHandle consoleHandle);

        void FontEqualTest(const ConsoleFontInfoEx& originalConsoleFontInfo, const ConsoleFontInfoEx& currentConsoleFontInfo);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_SET_CURRENT_CONSOLE_FONT_TESTING_H