///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:36)

#ifndef WINDOW_API_FRAME_TESTING_TESTING_HELPER_H
#define WINDOW_API_FRAME_TESTING_TESTING_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace WindowsAPIFrameTesting
{
    class TestingHelper : public Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        TestingHelper(WindowsHInstance hInstance, const char* lpCmdLine, const WindowApplicationInformation& information, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // WINDOW_API_FRAME_TESTING_TESTING_HELPER_H