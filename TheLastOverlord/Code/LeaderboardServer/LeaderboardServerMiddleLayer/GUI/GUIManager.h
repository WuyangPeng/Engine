///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/26 21:25)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerDll.h"

#include "LeaderboardServer/LeaderboardServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace LeaderboardServerMiddleLayer
{
    class LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = Framework::GUIManagerInterface;

    public:
        explicit GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
