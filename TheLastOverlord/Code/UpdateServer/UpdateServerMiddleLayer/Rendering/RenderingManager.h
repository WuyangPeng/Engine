///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 17:12)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define UPDATE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace UpdateServerMiddleLayer
{
    class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = Framework::RenderingManagerInterface;

    public:
        explicit RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // UPDATE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
