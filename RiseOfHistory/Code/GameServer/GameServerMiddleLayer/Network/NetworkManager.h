/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef GAME_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define GAME_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerDll.h"

#include "GameServer/GameServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/NetworkManagerInterface.h"

namespace GameServerMiddleLayer
{
    class GAME_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager final : public Framework::NetworkManagerInterface
    {
    public:
        using ClassType = NetworkManager;
        using ParentType = NetworkManagerInterface;

    public:
        NetworkManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
