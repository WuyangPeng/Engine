///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:50)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"

namespace GatewayServerMiddleLayer
{
    class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
    {
    public:
        using ClassType = NetworkManager;
        using ParentType = Framework::NetworkManagerInterface;

    public:
        explicit NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
