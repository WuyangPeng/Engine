// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:11)

#include "CoreTools/CoreToolsExport.h"

#include "BaseEntity.h"
#include "EntityManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BaseEntity
	::BaseEntity()
	:m_EntityID{ ENTITY_MANAGER_SINGLETON.NextUniqueID() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BaseEntity
	::~BaseEntity()
{
	if (!ENTITY_MANAGER_SINGLETON.Unregister(m_EntityID))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< SYSTEM_TEXT("ע��EntityID = ")
			<< m_EntityID
			<< SYSTEM_TEXT(" ʧ�ܡ�")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BaseEntity)

uint64_t CoreTools::BaseEntity
	::GetEntityID() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_EntityID;
}

void CoreTools::BaseEntity
	::Register()
{
	if (!ENTITY_MANAGER_SINGLETON.Register(shared_from_this()))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�ظ�ע��Entity"));
	}
	else
	{
		DoRegister();
	}
}

void CoreTools::BaseEntity
	::DoRegister()
{

}

