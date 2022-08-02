///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 14:57)

#ifndef MAIL_SERVER_MAIL_SERVER_HELPER_H
#define MAIL_SERVER_MAIL_SERVER_HELPER_H

#include "MailServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace MailServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, MailServerMessageWindowProcessHandle>;

    class MailServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = MailServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        MailServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MAIL_SERVER_MAIL_SERVER_HELPER_H
