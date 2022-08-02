///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 18:46)

#ifndef BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H
#define BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H

#include "BackgroundServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace BackgroundServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, BackgroundServerMessageWindowProcessHandle>;

    class BackgroundServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = BackgroundServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        BackgroundServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // BACKGROUND_SERVER_BACKGROUND_SERVER_HELPER_H
