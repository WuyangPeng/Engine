///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:59)

#ifndef FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H
#define FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H

#include "FrameworkTestingWindowMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace Framework
{
    using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, FrameworkHandle>;

    class TestingHelper final : public BaseType
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = BaseType;

    public:
        TestingHelper(WindowsHInstance instance,
                      const char* commandLine,
                      const WindowApplicationInformation& information,
                      const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_TESTING_HELPER_H
