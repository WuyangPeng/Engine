///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 21:22)

#ifndef DATABASE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define DATABASE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "DatabaseServer/DatabaseServerMiddleLayer/DatabaseServerMiddleLayerDll.h"

#include "DatabaseServer/DatabaseServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace DatabaseServerMiddleLayer
{
    class DATABASE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = Framework::AudioManagerInterface;

    public:
        explicit AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
