///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 22:25)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "RenderingManager.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

DatabaseGenerateServerMiddleLayer::RenderingManager::RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayer, RenderingManager)

bool DatabaseGenerateServerMiddleLayer::RenderingManager::Idle(int64_t timeDelta)
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = GetRenderer()->Draw(320, 320, Rendering::Colour<float>{ 0.0f, 0.3f, 0.4f, 1.0f }, "test");

    return ParentType::Idle(timeDelta);
}
