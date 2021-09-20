///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:37)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"

ResourceManager::ResourceManagerCopyUnsharedMacroImpl::ResourceManagerCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerCopyUnsharedMacroImpl)

int ResourceManager::ResourceManagerCopyUnsharedMacroImpl::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void ResourceManager::ResourceManagerCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    m_Count = count;
}
