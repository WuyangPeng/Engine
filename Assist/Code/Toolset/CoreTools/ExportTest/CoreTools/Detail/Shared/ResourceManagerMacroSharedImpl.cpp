///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:00)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerMacroSharedImpl::ResourceManagerMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerMacroSharedImpl)

int ResourceManager::ResourceManagerMacroSharedImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void ResourceManager::ResourceManagerMacroSharedImpl::SetCount(int count) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    mCount = count;
}
