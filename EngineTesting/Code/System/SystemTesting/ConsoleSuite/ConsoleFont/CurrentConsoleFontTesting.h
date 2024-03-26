/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:24)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CurrentConsoleFontTest(bool maximumWindow);

        void FontEqualTest(const ConsoleFontInfo& consoleFontInfo, const ConsoleFontInfoEx& consoleFontInfoEx);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CURRENT_CONSOLE_FONT_TESTING_H