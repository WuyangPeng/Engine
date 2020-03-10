// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:06)

#include "CoreTools/CoreToolsExport.h"

#include "BaseResourceImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BaseResourceImpl
	::BaseResourceImpl(PriorityType priority)
	:m_Priority{ priority }, m_ReferenceCount{ 0 },
	 m_LastAccessTime{ boost::posix_time::second_clock::local_time() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BaseResourceImpl
	::IsValid() const noexcept
{
	if (0 <= m_ReferenceCount)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::PriorityType CoreTools::BaseResourceImpl
	::GetPriority() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Priority;
}

boost::posix_time::ptime CoreTools::BaseResourceImpl
	::GetLastAccessTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_LastAccessTime;
}

bool CoreTools::BaseResourceImpl
	::IsLocked() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return (0 < m_ReferenceCount) ? true : false;
}

void CoreTools::BaseResourceImpl
	::SetPriority(PriorityType priority) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Priority = priority;
}

void CoreTools::BaseResourceImpl
	::SetCurrentTime()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	// 您可能需要添加操作系统依赖的方法，来获取当前时间来设置你的资源访问时间。
	m_LastAccessTime = boost::posix_time::second_clock::local_time();
}

void CoreTools::BaseResourceImpl
	::Lock() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	++m_ReferenceCount;
}

void CoreTools::BaseResourceImpl
	::Unlock() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		CORE_TOOLS_ASSERTION_2(0 < m_ReferenceCount, "资源未加锁。");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	--m_ReferenceCount;
}


