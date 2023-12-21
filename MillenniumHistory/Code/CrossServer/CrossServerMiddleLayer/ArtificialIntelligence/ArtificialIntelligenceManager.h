/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/17 20:09)

#ifndef CROSS_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H
#define CROSS_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H

#include "CrossServer/CrossServerMiddleLayer/CrossServerMiddleLayerDll.h"

#include "CrossServer/CrossServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"

namespace CrossServerMiddleLayer
{
    class CROSS_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntelligenceManager final : public Framework::ArtificialIntelligenceInterface
    {
    public:
        using ClassType = ArtificialIntelligenceManager;
        using ParentType = ArtificialIntelligenceInterface;

    public:
        ArtificialIntelligenceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CROSS_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE_H
