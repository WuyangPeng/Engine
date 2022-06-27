///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 16:21)

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