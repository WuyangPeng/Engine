/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#ifndef ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
#define ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H

#include "RobotClientMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace RobotClient
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, RobotClientMessageWindowProcessHandle>;

    class RobotClientHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = RobotClientHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        RobotClientHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ROBOT_CLIENT_ROBOT_CLIENT_HELPER_H
