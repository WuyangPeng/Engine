///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 15:39)

#ifndef GAME_CLIENT_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H
#define GAME_CLIENT_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemManager;
        using ParentType = SystemManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_SYSTEM_SYSTEM_MANAGER_H
