/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:26)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/ResourceManagerMacroSharedImpl.h"

ResourceManager::ResourceManagerMacroShared::ResourceManagerMacroShared(int count)
    : impl{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerMacroShared)

int ResourceManager::ResourceManagerMacroShared::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ResourceManager::ResourceManagerMacroShared::SetCount(int count) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* ResourceManager::ResourceManagerMacroShared::GetAddress() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}