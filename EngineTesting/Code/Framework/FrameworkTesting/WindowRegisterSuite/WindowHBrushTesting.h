///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 20:29)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_H_BRUSH_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_H_BRUSH_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

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
        void DoRunUnitTest() override;

        void MainTest();

        void BrushTest();

    private:
        using Container = std::vector<System::WindowsBrushTypes>;

    private:
        Container container;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_H_BRUSH_TESTING_H