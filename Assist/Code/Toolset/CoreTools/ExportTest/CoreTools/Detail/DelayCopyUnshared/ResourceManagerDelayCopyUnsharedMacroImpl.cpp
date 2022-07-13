///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/01 14:13)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerDelayCopyUnsharedMacroImpl::ResourceManagerDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerDelayCopyUnsharedMacroImpl)

int ResourceManager::ResourceManagerDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void ResourceManager::ResourceManagerDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    mCount = count;
}
