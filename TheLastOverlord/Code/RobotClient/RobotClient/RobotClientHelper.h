///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 17:18)

#ifndef ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
#define ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H

#include "RobotClientMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace RobotClient
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, RobotClientMessageWindowProcessHandle>;

    class RobotClientHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = RobotClientHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        RobotClientHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
