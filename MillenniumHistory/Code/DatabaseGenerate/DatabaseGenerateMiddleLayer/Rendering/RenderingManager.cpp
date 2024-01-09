/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:55)

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/DatabaseGenerateMiddleLayerClassInvariantMacro.h"
#include "RenderingManager.h"
#include "Rendering/RendererEngine/BaseRenderer.h"

DatabaseGenerateMiddleLayer::RenderingManager::RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    DATABASE_GENERATE_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayer, RenderingManager)

bool DatabaseGenerateMiddleLayer::RenderingManager::Idle(int64_t timeDelta)
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = GetRenderer()->Draw(320, 320, Rendering::Colour{ 1.0f, 0.3f, 0.4f, 1.0f }, "test");

    return ParentType::Idle(timeDelta);
}
