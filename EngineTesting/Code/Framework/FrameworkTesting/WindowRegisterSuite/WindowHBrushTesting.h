///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 16:31)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include <vector>

namespace Framework
{
    class WindowHBrushTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowHBrushTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowHBrushTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void BrushTest();

    private:
        using Container = std::vector<System::WindowsBrushTypes>;

    private:
        Container container;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H