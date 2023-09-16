///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:55)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsFontInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsFontInformationTesting;
        using ParentType = UnitTest;

    public:
        WindowsFontInformationTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetFontInformationTest();
        void FontInformationTest();

        void DoFontInformationTest(WindowsHdc context);

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H