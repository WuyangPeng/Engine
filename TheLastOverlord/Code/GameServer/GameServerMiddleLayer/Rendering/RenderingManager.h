///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 22:04)

#ifndef GAME_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define GAME_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerDll.h"

#include "GameServer/GameServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace GameServerMiddleLayer
{
    class GAME_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = Framework::RenderingManagerInterface;

    public:
        explicit RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
