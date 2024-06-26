///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:32)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowPointTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowPointTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowPointTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void DefaultTest() noexcept;
        void RandomTest();
        void WindowPointUseTest() noexcept;
        void LParamTest();
        void EqualTest();
        void OStreamTest();
        void ConstexprTest() noexcept;

    private:
        static constexpr System::WindowsWord gWordShift{ 16 };
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_POINT_TESTING_H