/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace GameMasterServerMiddleLayer
{
    class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager final : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = AudioManagerInterface;

    public:
        AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
