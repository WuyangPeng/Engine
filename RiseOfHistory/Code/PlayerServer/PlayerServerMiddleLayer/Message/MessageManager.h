/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#ifndef PLAYER_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define PLAYER_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "PlayerServer/PlayerServerMiddleLayer/PlayerServerMiddleLayerDll.h"

#include "PlayerServer/PlayerServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"

namespace PlayerServerMiddleLayer
{
    class PLAYER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager final : public Framework::MessageManagerInterface
    {
    public:
        using ClassType = MessageManager;
        using ParentType = MessageManagerInterface;

    public:
        MessageManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // PLAYER_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
