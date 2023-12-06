/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace LoginServerMiddleLayer
{
    class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager final : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = EventManagerInterface;

    public:
        EventManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOGIN_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
