///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/20 11:18)

#ifndef GAME_CLIENT_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define GAME_CLIENT_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = Framework::EventManagerInterface;

    public:
        explicit EventManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
