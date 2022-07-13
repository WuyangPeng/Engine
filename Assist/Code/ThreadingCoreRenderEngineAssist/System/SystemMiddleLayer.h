///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 14:00)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_SYSTEM_MIDDLE_LAYER_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_SYSTEM_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/SystemManagerInterface.h"

namespace ThreadingCoreRenderEngineAssist
{
    class SystemMiddleLayer final : public Framework::SystemManagerInterface
    {
    public:
        using ClassType = SystemMiddleLayer;
        using ParentType = SystemManagerInterface;
        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;

    public:
        explicit SystemMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Execute(int select);
    };
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_SYSTEM_MIDDLE_LAYER_H
