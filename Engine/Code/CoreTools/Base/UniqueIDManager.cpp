///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 15:51)

#include "CoreTools/CoreToolsExport.h"

#include "UniqueIDManagerDetail.h"
#include "Flags/UniqueIdSelect.h"
#include "Detail/UniqueIdManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#include <memory>

SINGLETON_GET_PTR_DEFINE(CoreTools, UniqueIDManager);

CoreTools::UniqueIdManager::UniqueIdManagerUniquePtr CoreTools::UniqueIdManager::uniqueIdManager{};

void CoreTools::UniqueIdManager::Create(int count)
{
    if (uniqueIdManager != nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("重复初始化UniqueIDManager。"))
    }

    uniqueIdManager = std::make_unique<UniqueIdManager>(count, UniqueIdManagerCreate::Init);
}

void CoreTools::UniqueIdManager::Destroy() noexcept
{
    uniqueIdManager.reset();
}

CoreTools::UniqueIdManager::UniqueIdManager(int count, UniqueIdManagerCreate uniqueIdManagerCreate)
    : impl{ count }
{
    System::UnusedFunction(uniqueIdManagerCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UniqueIdManager)

uint64_t CoreTools::UniqueIdManager::NextDefaultUniqueId()
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueId(UniqueIdSelect::Default);
}

uint64_t CoreTools::UniqueIdManager::NextUniqueId(int index)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->NextUniqueId(index);
}

void CoreTools::UniqueIdManager::SetUniqueId(int index, uint64_t latestIndex)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetUniqueId(index, latestIndex);
}
