///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:54)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace Framework
{
    class WindowPictorialTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowPictorialTesting;
        using ParentType = UnitTest;

        using TChar = System::TChar;
        using WindowsHInstance = System::WindowsHInstance;

    public:
        explicit WindowPictorialTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using IconContainer = std::vector<std::pair<int, const TChar*>>;
        using CursorContainer = std::vector<std::pair<int, const TChar*>>;
        using BrushContainer = std::vector<System::WindowsBrushTypes>;
        using IconContainerConstIter = IconContainer::const_iterator;
        using CursorContainerConstIter = CursorContainer::const_iterator;
        using BrushContainerConstIter = BrushContainer::const_iterator;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void BrushTest();

        void RandomContainer();

        void RandomIconTest();
        void RandomCursorTest();
        void RandomBrushTest();
        void RandomIconAndCursorTest();

        void DefaultIconTest();
        void DefaultCursorTest();
        void DefaultIconAndCursorTest();
        void CustomIconAndCursorTest();

        NODISCARD bool ExecuteWindowPictorialTest();

    private:
        WindowsHInstance instance;
        IconContainer iconContainer;
        CursorContainer cursorContainer;
        BrushContainer brushContainer;
        std::default_random_engine generator;
        int index;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
