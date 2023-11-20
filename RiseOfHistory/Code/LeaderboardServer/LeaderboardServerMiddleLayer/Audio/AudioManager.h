/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef LEADERBOARD_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define LEADERBOARD_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "LeaderboardServer/LeaderboardServerMiddleLayer/LeaderboardServerMiddleLayerDll.h"

#include "LeaderboardServer/LeaderboardServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace LeaderboardServerMiddleLayer
{
    class LEADERBOARD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager final : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = AudioManagerInterface;

    public:
        AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LEADERBOARD_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
