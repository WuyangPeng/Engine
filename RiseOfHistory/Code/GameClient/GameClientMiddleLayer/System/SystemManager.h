/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:42)

#ifndef GAME_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define GAME_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

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

    public:
        SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H