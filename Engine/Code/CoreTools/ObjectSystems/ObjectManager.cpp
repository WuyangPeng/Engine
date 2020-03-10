// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectManager.h"
#include "Detail/ObjectManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

SINGLETON_MUTEX_DEFINE(CoreTools, ObjectManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_CoreToolsMutex }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_ObjectManagerMutex }

SINGLETON_INITIALIZE_DEFINE(CoreTools, ObjectManager)

SINGLETON_DEFINE(CoreTools, ObjectManager)

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ObjectManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ObjectManager::FactoryFunction CoreTools::ObjectManager
	::Find(const string& name) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->Find(name);
}

void CoreTools::ObjectManager
	::Insert(const string& name, FactoryFunction function)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Insert(name, function);
}

void CoreTools::ObjectManager
	::Remove(const string& name)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Remove(name);
}

uint64_t CoreTools::ObjectManager
	::NextUniqueID()
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->NextUniqueID();
}



