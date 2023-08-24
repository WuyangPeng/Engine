///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:53)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class FontInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FontInformationTesting;
        using ParentType = UnitTest;

        using WindowsHWnd = System::WindowsHWnd;

    public:
        FontInformationTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void WindowFontInformationTest();
        void GlutFontInformationTest();

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
