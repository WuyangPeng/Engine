///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:18)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerCopyUnsharedMacroImpl::ResourceManagerCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerCopyUnsharedMacroImpl)

int ResourceManager::ResourceManagerCopyUnsharedMacroImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return count;
}

void ResourceManager::ResourceManagerCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    count = aCount;
}
