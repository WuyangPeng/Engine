///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/20 11:06)

#ifndef GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
    {
    public:
        using ClassType = ResourceManager;
        using ParentType = Framework::ResourceManagerInterface;

    public:
        explicit ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
