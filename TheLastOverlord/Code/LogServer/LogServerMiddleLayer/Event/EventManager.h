/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef LOG_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define LOG_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/EventManagerInterface.h"

namespace LogServerMiddleLayer
{
    class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager final : public Framework::EventManagerInterface
    {
    public:
        using ClassType = EventManager;
        using ParentType = EventManagerInterface;

    public:
        EventManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOG_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
