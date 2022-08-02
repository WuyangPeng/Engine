///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/20 11:17)

#ifndef GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = Framework::GUIManagerInterface;

    public:
        explicit GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
