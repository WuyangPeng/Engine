///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/24 0:53)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace LoginServerMiddleLayer
{
    class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = Framework::EventManagerInterface;

    public:
        explicit EventManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
