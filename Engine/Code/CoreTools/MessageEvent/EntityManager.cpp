// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.2 (2020/01/22 17:14)

#include "CoreTools/CoreToolsExport.h"

#include "EntityManager.h"
#include "Detail/EntityManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_MUTEX_DEFINE(CoreTools, EntityManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetCoreToolsMutex() }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_EntityManagerMutex }

SINGLETON_INITIALIZE_DEFINE(CoreTools, EntityManager)

SINGLETON_DEFINE(CoreTools, EntityManager)

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::EntityManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint64_t CoreTools::EntityManager
	::NextUniqueID()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->NextUniqueID();
}

bool CoreTools::EntityManager
	::Register(const EntityPtr& entity)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Register(entity);
}

bool CoreTools::EntityManager
	::Unregister(uint64_t entityID)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unregister(entityID);
}

CoreTools::EntityManager::EntityPtr CoreTools::EntityManager
	::GetEntity(uint64_t entityID) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetEntity(entityID);
}

