///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 0:59)

#ifndef LOGIN_SERVER_LOGIN_SERVER_HELPER_H
#define LOGIN_SERVER_LOGIN_SERVER_HELPER_H

#include "LoginServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace LoginServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, LoginServerMessageWindowProcessHandle>;

    class LoginServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = LoginServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        LoginServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOGIN_SERVER_LOGIN_SERVER_HELPER_H
