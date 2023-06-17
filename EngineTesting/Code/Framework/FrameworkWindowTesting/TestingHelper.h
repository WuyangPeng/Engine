///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:07)

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
