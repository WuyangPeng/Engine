///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 17:01)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowSizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void DefaultTest();
        void RandomTest();
        void LParamTest();
        void EqualTest();
        void SetWindowSizeTest();
        void SetWindowSizeExceptionTest(int width, int height);
        void OstreamTest();
        void NegativeTest();
        void WindowSizeExceptionTest(int width, int height);
        void SetNegative(int index, int& width, int& height) noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_SIZE_TESTING_H