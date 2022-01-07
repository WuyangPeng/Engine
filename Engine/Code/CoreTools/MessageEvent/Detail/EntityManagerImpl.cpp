///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:29)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
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

    return container.insert({ entity->GetEntityID(), entity }).second;
}

bool CoreTools::EntityManagerImpl::Unregister(uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.erase(entityID) != 0;
}

CoreTools::EntityManagerImpl::EntitySharedPtr CoreTools::EntityManagerImpl::GetEntity(uint64_t entityID) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto entity = container.find(entityID);
    if (entity != container.cend())
    {
        auto ptr = entity->second.lock();

        if (!ptr)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("Entity已释放。"s));
        }

        return ptr;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Entity不存在。"s));
    }
}
