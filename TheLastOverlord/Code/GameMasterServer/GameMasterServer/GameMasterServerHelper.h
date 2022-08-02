///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 22:29)

#ifndef GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H
#define GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H

#include "GameMasterServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace GameMasterServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, GameMasterServerMessageWindowProcessHandle>;

    class GameMasterServerHelper : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = GameMasterServerHelper;
        using ParentType = WindowMainFunctionHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        explicit GameMasterServerHelper(WindowsHInstance instance, char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_GAME_MASTER_SERVER_HELPER_H
