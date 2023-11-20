/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define FIGHTING_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace FightingServerMiddleLayer
{
    class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = GUIManagerInterface;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FIGHTING_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
