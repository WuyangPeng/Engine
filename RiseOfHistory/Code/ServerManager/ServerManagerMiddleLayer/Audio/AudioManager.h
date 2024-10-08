/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:50)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define SERVER_MANAGER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "ServerManager/ServerManagerMiddleLayer/ServerManagerMiddleLayerDll.h"

#include "ServerManager/ServerManagerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace ServerManagerMiddleLayer
{
    class SERVER_MANAGER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager final : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = AudioManagerInterface;

    public:
        AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // SERVER_MANAGER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H