/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace BackgroundServerMiddleLayer
{
    class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager final : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = EventManagerInterface;

    public:
        EventManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // BACKGROUND_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
