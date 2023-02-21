///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:19)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerTestExportMacroImpl::ResourceManagerTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerTestExportMacroImpl)

int ResourceManager::ResourceManagerTestExportMacroImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return count;
}

void ResourceManager::ResourceManagerTestExportMacroImpl::SetCount(int aCount) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    count = aCount;
}
