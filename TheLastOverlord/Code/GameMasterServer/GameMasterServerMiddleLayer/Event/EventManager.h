/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:43)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace GameMasterServerMiddleLayer
{
    class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = EventManagerInterface;

    public:
        EventManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
