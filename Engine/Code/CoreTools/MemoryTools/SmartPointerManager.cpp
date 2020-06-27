// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/21 13:36)

#include "CoreTools/CoreToolsExport.h"

#include "SmartPointerManager.h"
#include "Detail/SmartPointerManagerImpl.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_MUTEX_DEFINE(CoreTools, SmartPointerManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ GetCoreToolsMutex() }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_SmartPointerManagerMutex }

SINGLETON_INITIALIZE_DEFINE(CoreTools, SmartPointerManager)

SINGLETON_DEFINE(CoreTools, SmartPointerManager)

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SmartPointerManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::SmartPointerManager
	::CopyIncreaseReference(const void* data)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->CopyIncreaseReference(data);
}

int CoreTools::SmartPointerManager
	::IncreaseReference(const void* data)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->IncreaseReference(data);
}

int CoreTools::SmartPointerManager
	::DecreaseReference(const void* data)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DecreaseReference(data);
}

bool CoreTools::SmartPointerManager
	::IsSmartPointer(const void* data) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsSmartPointer(data);
}

