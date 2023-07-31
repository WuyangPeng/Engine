///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 22:34)

#ifndef DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H
#define DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace DatabaseGenerateServerMiddleLayer
{
    class DATABASE_GENERATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = Framework::RenderingManagerInterface;

    public:
        RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Idle(int64_t timeDelta) override;
    };
}

#endif  // DATABASE_GENERATE_SERVER_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H
