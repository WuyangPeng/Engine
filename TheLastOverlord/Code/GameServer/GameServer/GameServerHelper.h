/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#ifndef GAME_SERVER_GAME_SERVER_HELPER_H
#define GAME_SERVER_GAME_SERVER_HELPER_H

#include "GameServerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

namespace GameServer
{
    using WindowMainFunctionHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, GameServerMessageWindowProcessHandle>;

    class GameServerHelper final : public WindowMainFunctionHelperBase
    {
    public:
        using ClassType = GameServerHelper;
        using ParentType = WindowMainFunctionHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;

    public:
        GameServerHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_SERVER_GAME_SERVER_HELPER_H
