// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 17:14)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManager.h"
#include "Detail/EntityManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, EntityManager);

CoreTools::EntityManager::EntityManagerUniquePtr CoreTools::EntityManager
	::sm_EntityManager{ };

void CoreTools::EntityManager
	::Create()
{
	sm_EntityManager = make_unique<CoreTools::EntityManager>(EntityManagerCreate::Init);
}

void CoreTools::EntityManager
	::Destroy() noexcept
{
	sm_EntityManager.reset();
}

CoreTools::EntityManager
	::EntityManager(EntityManagerCreate entityManagerCreate)
	:m_Impl{ make_shared<ImplType>() }
{
	SYSTEM_UNUSED_ARG(entityManagerCreate);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, EntityManager)

uint64_t CoreTools::EntityManager
	::NextUniqueID()
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->NextUniqueID();
}

bool CoreTools::EntityManager
	::Register(const EntityPtr& entity)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Register(entity);
}

bool CoreTools::EntityManager
	::Unregister(uint64_t entityID)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unregister(entityID);
}

CoreTools::EntityManager::EntityPtr CoreTools::EntityManager
	::GetEntity(uint64_t entityID) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetEntity(entityID);
}

