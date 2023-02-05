///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 11:25)

#ifndef GAME_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define GAME_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = Framework::AudioManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
