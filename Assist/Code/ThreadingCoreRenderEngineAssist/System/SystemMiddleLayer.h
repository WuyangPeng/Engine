///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/20 10:47)

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
