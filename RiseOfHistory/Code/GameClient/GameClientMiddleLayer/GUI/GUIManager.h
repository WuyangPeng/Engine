///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 11:23)

#ifndef GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = Framework::GUIManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
