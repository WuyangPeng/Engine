///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 16:04)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define FIGHTING_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/MessageManagerInterface.h"

namespace FightingServerMiddleLayer
{
    class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager : public Framework::MessageManagerInterface
    {
    public:
        using ClassType = MessageManager;
        using ParentType = Framework::MessageManagerInterface;

    public:
        explicit MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FIGHTING_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
