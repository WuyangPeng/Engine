///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:42)

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManagerCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ResourceManagerClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/ResourceManagerCopyUnsharedMacroImpl.h"

ResourceManager::ResourceManagerCopyUnsharedMacro::ResourceManagerCopyUnsharedMacro(int count)
    : impl{ count }
{
    RESOURCE_MANAGER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ResourceManager, ResourceManagerCopyUnsharedMacro)

int ResourceManager::ResourceManagerCopyUnsharedMacro::GetCount() const noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ResourceManager::ResourceManagerCopyUnsharedMacro::SetCount(int count) noexcept
{
    RESOURCE_MANAGER_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(ResourceManager, ResourceManagerCopyUnsharedMacro)