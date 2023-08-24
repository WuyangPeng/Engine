///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 22:23)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Resource/ResourceManager.h"
#include "SystemManager.h"
#include "Detail/SystemManagerImpl.h"

DatabaseGenerateServerMiddleLayer::SystemManager::SystemManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ "Configuration/Database.json" }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayer, SystemManager)

bool DatabaseGenerateServerMiddleLayer::SystemManager::Idle(int64_t timeDelta)
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    System::UnusedFunction(timeDelta);

    const auto resource = GetResourceManager<ResourceManager>();

    if (const auto ancientBooksContainer = resource->GetAncientBooksContainer();
        ancientBooksContainer != nullptr)
    {
        return impl->Idle(*ancientBooksContainer);
    }

    return true;
}

bool DatabaseGenerateServerMiddleLayer::SystemManager::Initialize()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Initialize();
}

bool DatabaseGenerateServerMiddleLayer::SystemManager::Destroy() noexcept
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Destroy();
}
