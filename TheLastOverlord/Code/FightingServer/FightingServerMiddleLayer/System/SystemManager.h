///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 15:57)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define FIGHTING_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace FightingServerMiddleLayer
{
    class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemManager;
        using ParentType = Framework::SystemManagerInterface;

    public:
        explicit SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FIGHTING_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
