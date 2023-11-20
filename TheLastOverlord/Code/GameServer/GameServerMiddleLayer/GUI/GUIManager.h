/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef GAME_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define GAME_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerDll.h"

#include "GameServer/GameServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace GameServerMiddleLayer
{
    class GAME_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = GUIManagerInterface;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
