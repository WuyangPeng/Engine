/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:42)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerDll.h"

#include "RobotClient/RobotClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"

namespace RobotClientMiddleLayer
{
    class ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
    {
    public:
        using ClassType = NetworkManager;
        using ParentType = NetworkManagerInterface;

    public:
        NetworkManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
