//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:45)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManagerImpl.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/BaseEntity.h"

using namespace std::literals;

CoreTools::EntityManagerImpl::EntityManagerImpl(MAYBE_UNUSED int count) noexcept
    : m_Container{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EntityManagerImpl)

bool CoreTools::EntityManagerImpl::Register(const EntitySharedPtr& entity)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_Container.insert({ entity->GetEntityID(), entity }).second;
}

bool CoreTools::EntityManagerImpl::Unregister(uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_Container.erase(entityID) != 0;
}

CoreTools::EntityManagerImpl::EntitySharedPtr CoreTools::EntityManagerImpl::GetEntity(uint64_t entityID) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto entity = m_Container.find(entityID);
    if (entity != m_Container.cend())
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
