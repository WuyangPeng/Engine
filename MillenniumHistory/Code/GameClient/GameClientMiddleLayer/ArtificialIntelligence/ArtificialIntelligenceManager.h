///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/13 22:04)

#ifndef GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H
#define GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntelligenceManager : public Framework::ArtificialIntellegenceInterface
    {
    public:
        using ClassType = ArtificialIntelligenceManager;
        using ParentType = Framework::ArtificialIntellegenceInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ArtificialIntelligenceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H
