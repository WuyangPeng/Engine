///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 18:42)

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