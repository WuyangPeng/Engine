/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:50)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/BaseEntity.h"

CoreTools::EntityManagerImpl::EntityManagerImpl() noexcept
    : container{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EntityManagerImpl)

bool CoreTools::EntityManagerImpl::Register(const EntitySharedPtr& entity)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.emplace(entity->GetEntityId(), entity).second;
}

bool CoreTools::EntityManagerImpl::UnRegister(int64_t entityId) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.erase(entityId) != 0;
}

CoreTools::EntityManagerImpl::EntitySharedPtr CoreTools::EntityManagerImpl::GetEntity(int64_t entityId) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto entity = container.find(entityId); entity != container.cend())
    {
        auto ptr = entity->second.lock();

        if (!ptr)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("Entity已释放。"s))
        }

        return ptr;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Entity不存在。"s))
    }
}
