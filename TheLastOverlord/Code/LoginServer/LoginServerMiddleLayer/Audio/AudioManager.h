///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 0:56)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define LOGIN_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace LoginServerMiddleLayer
{
    class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = Framework::AudioManagerInterface;

    public:
        explicit AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // LOGIN_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
