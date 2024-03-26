/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:04)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerTestExportCopyMacroImpl::ResourceManagerTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerTestExportCopyMacroImpl)

int ResourceManager::ResourceManagerTestExportCopyMacroImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return count;
}

void ResourceManager::ResourceManagerTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    count = aCount;
}
