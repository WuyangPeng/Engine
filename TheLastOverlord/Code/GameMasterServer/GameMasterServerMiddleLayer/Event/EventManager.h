///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 22:26)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace GameMasterServerMiddleLayer
{
    class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = Framework::EventManagerInterface;

    public:
        explicit EventManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
