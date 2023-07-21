///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 22:30)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "ResourceManager.h"
#include "Detail/ResourceManagerImpl.h"

DatabaseGenerateServerMiddleLayer::ResourceManager::ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ SYSTEM_TEXT("Resource/AncientBooksCsv") }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayer, ResourceManager)

bool DatabaseGenerateServerMiddleLayer::ResourceManager::Initialize()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Initialize();
}

bool DatabaseGenerateServerMiddleLayer::ResourceManager::Destroy() noexcept
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Destroy();
}

DatabaseGenerateServerMiddleLayer::ResourceManager::ConstAncientBooksContainerSharedPtr DatabaseGenerateServerMiddleLayer::ResourceManager::GetAncientBooksContainer()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->GetAncientBooksContainer();
}
