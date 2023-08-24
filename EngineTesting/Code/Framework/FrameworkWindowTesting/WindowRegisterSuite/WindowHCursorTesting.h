///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:49)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_H_CURSOR_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_H_CURSOR_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace Framework
{
    class WindowHCursorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowHCursorTesting;
        using ParentType = UnitTest;

        using TChar = System::TChar;
        using WindowsHInstance = System::WindowsHInstance;

    public:
        explicit WindowHCursorTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void ConstructorTest();
        void CreateTest();

    private:
        using HCursorContainer = std::map<int, const TChar*>;

    private:
        WindowsHInstance instance;
        HCursorContainer container;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_H_CURSOR_TESTING_H