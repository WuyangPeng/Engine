/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 22:56)

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerExport.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/DatabaseGenerateMiddleLayerClassInvariantMacro.h"
#include "ResourceManager.h"
#include "Detail/ResourceManagerImpl.h"

DatabaseGenerateMiddleLayer::ResourceManager::ResourceManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      impl{ SYSTEM_TEXT("Resource/AncientBooksCsv") }
{
    DATABASE_GENERATE_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayer, ResourceManager)

bool DatabaseGenerateMiddleLayer::ResourceManager::Initialize()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Initialize();
}

bool DatabaseGenerateMiddleLayer::ResourceManager::Destroy() noexcept
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->Destroy();
}

DatabaseGenerateMiddleLayer::ResourceManager::ConstAncientBooksContainerSharedPtr DatabaseGenerateMiddleLayer::ResourceManager::GetAncientBooksContainer()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    return impl->GetAncientBooksContainer();
}
