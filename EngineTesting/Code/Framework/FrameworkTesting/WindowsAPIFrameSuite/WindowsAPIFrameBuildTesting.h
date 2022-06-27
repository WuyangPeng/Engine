///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 16:21)

#ifndef FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H
#define FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowsAPIFrameBuildTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsAPIFrameBuildTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsAPIFrameBuildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

    private:
        void MainTest();
    };
}

#endif  // FRAMEWORK_WINDOW_API_FRAME_SUITE_WINDOW_MESSAGE_LOOP_TESTING_H