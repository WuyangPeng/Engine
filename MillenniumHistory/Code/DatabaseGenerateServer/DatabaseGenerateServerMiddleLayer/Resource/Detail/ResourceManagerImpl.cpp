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
#include "ResourceManagerImpl.h"
#include "CoreTools/Helper/LogMacro.h"

DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::ResourceManagerImpl(const String& directory)
    : directory{ directory },
      ancientBooksContainer{},
      thread{},
      mutex{}
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerMiddleLayer, ResourceManagerImpl)

bool DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::Initialize()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread = std::make_shared<std::jthread>(&ClassType::InitAncientBooks, this);

    return true;
}

bool DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::Destroy() noexcept
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread.reset();

    return true;
}

DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::ConstAncientBooksContainerSharedPtr DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::GetAncientBooksContainer()
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9;

    std::unique_lock unique_lock{ mutex };

    return ancientBooksContainer;
}

void DatabaseGenerateServerMiddleLayer::ResourceManagerImpl::InitAncientBooks()
{
    const auto result = std::make_shared<AncientBooks::AncientBooksContainer>(directory);

    std::unique_lock unique_lock{ mutex };

    ancientBooksContainer = result;
}
