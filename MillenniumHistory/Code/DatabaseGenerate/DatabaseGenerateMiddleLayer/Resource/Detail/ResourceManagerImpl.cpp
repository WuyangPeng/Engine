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
#include "ResourceManagerImpl.h"
#include "CoreTools/Helper/LogMacro.h"

DatabaseGenerateMiddleLayer::ResourceManagerImpl::ResourceManagerImpl(const String& directory)
    : directory{ directory },
      ancientBooksContainer{},
      thread{},
      mutex{}
{
    DATABASE_GENERATE_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateMiddleLayer, ResourceManagerImpl)

bool DatabaseGenerateMiddleLayer::ResourceManagerImpl::Initialize()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread = std::make_shared<std::jthread>(&ClassType::InitAncientBooks, this);

    return true;
}

bool DatabaseGenerateMiddleLayer::ResourceManagerImpl::Destroy() noexcept
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    thread.reset();

    return true;
}

DatabaseGenerateMiddleLayer::ResourceManagerImpl::ConstAncientBooksContainerSharedPtr DatabaseGenerateMiddleLayer::ResourceManagerImpl::GetAncientBooksContainer()
{
    DATABASE_GENERATE_MIDDLE_LAYER_CLASS_IS_VALID_9;

    std::unique_lock uniqueLock{ mutex };

    return ancientBooksContainer;
}

void DatabaseGenerateMiddleLayer::ResourceManagerImpl::InitAncientBooks()
{
    const auto result = std::make_shared<AncientBooks::AncientBooksContainer>(directory);

    std::unique_lock uniqueLock{ mutex };

    ancientBooksContainer = result;
}
