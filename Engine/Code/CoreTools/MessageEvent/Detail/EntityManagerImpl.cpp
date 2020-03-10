// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.1 (2019/06/28 17:56)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManagerImpl.h"
#include "CoreTools/MessageEvent/BaseEntity.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::EntityManagerImpl
	::EntityManagerImpl()
	:m_Container{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

uint64_t CoreTools::EntityManagerImpl
	::NextUniqueID()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity);
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EntityManagerImpl)

bool CoreTools::EntityManagerImpl
	::Register(const EntityPtr& entity)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Container.insert({ entity->GetEntityID(), entity }).second;
}

bool CoreTools::EntityManagerImpl
	::Unregister(uint64_t entityID)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Container.erase(entityID) != 0;
}

CoreTools::EntityManagerImpl::EntityPtr CoreTools::EntityManagerImpl
	::GetEntity(uint64_t entityID) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto entity = m_Container.find(entityID);
	if (entity != m_Container.cend())
	{
		auto ptr = entity->second.lock();

		if (!ptr)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("Entity已释放。"));
		}

		return ptr;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Entity不存在。"));
	}
}
