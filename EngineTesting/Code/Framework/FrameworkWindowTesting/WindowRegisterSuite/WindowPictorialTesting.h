///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 13:55)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <map>
#include <random>

namespace Framework
{
    class WindowPictorialTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowPictorialTesting;
        using ParentType = UnitTest;
        using TChar = System::TChar;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowPictorialTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using IconContainer = std::vector<std::pair<int, const TChar*>>;
        using CursorContainer = std::vector<std::pair<int, const TChar*>>;
        using BrushContainer = std::vector<System::WindowsBrushTypes>;
        using IconContainerConstIter = IconContainer::const_iterator;
        using CursorContainerConstIter = CursorContainer::const_iterator;
        using BrushContainerConstIter = BrushContainer::const_iterator;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void BrushTest();
        void RandomTest();

        void RandomContainer(std::default_random_engine& generator);

        void RandomIconTest();
        void RandomCursorTest();
        void RandomBrushTest();
        void RandomIconAndCursorTest();

        void DefaultIconTest();
        void DefaultCursorTest();
        void DefaultIconAndCursorTest();
        void CustomIconAndCursorTest();

        void NextIcon(std::default_random_engine& generator);
        void NextCursor(std::default_random_engine& generator);
        void NextBrush(std::default_random_engine& generator);

    private:
        HInstance instance;
        IconContainer iconContainer;
        CursorContainer cursorContainer;
        BrushContainer brushContainer;
        IconContainer testIconContainer;
        CursorContainer testCursorContainer;
        BrushContainer testBrushContainer;
        IconContainerConstIter iconIter;
        CursorContainerConstIter cursorIter;
        BrushContainerConstIter brushIter;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
