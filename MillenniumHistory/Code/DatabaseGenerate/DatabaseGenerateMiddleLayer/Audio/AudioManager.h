/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 22:49)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define DATABASE_GENERATE_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/AudioManagerInterface.h"

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager final : public Framework::AudioManagerInterface
    {
    public:
        using ClassType = AudioManager;
        using ParentType = AudioManagerInterface;

    public:
        AudioManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
