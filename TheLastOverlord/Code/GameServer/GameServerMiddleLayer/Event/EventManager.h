///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 22:08)

#ifndef GAME_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define GAME_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerDll.h"

#include "GameServer/GameServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace GameServerMiddleLayer
{
    class GAME_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = Framework::EventManagerInterface;

    public:
        explicit EventManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
