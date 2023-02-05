///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/04 11:03)

#ifndef GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
    {
    public:
        using ClassType = ResourceManager;
        using ParentType = Framework::ResourceManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
