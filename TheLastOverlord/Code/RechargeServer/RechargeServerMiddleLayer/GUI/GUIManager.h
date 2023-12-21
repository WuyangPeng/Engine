/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define RECHARGE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "RechargeServer/RechargeServerMiddleLayer/RechargeServerMiddleLayerDll.h"

#include "RechargeServer/RechargeServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace RechargeServerMiddleLayer
{
    class RECHARGE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager final : public Framework::GUIManagerInterface
    {
    public:
        using ClassType = GUIManager;
        using ParentType = GUIManagerInterface;

    public:
        GUIManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // RECHARGE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
