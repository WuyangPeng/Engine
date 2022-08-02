///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 16:11)

#ifndef FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H
#define FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H

#include "FightingServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace FightingServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, FightingServerMessageWindowProcessHandle>;

    class FightingServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = FightingServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        FightingServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FIGHTING_SERVER_FIGHTING_SERVER_HELPER_H
