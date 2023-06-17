///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 21:39)

#ifndef LOG_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define LOG_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"

namespace LogServerMiddleLayer
{
    class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
    {
    public:
        using ClassType = NetworkManager;
        using ParentType = Framework::NetworkManagerInterface;

    public:
        NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOG_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
