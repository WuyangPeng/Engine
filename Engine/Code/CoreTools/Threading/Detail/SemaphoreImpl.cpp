// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:22)

#include "CoreTools/CoreToolsExport.h"

#include "SemaphoreImpl.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SemaphoreImpl
	::SemaphoreImpl(int initialCount, int maximumCount)
	:m_Handle{ System::CreateSystemSemaphore(initialCount, maximumCount) },
	 m_CurrentCount{ initialCount }, m_MaximumCount{ maximumCount }
{
	if (!System::IsSystemSemaphoreValid(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���ź���ʧ�ܣ�"s));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SemaphoreImpl
	::~SemaphoreImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	if (!System::CloseSystemSemaphore(m_Handle))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("�����ź���ʧ�ܣ�")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SemaphoreImpl
	::IsValid() const noexcept
{
	if (System::IsSystemSemaphoreValid(m_Handle) && 0 <= m_CurrentCount && m_CurrentCount <= m_MaximumCount)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::SemaphoreImpl
	::Release(int releaseCount)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_1(0 < releaseCount, "Ҫ�ͷŵ��ź�����ĿΪ������");

	if (!System::ReleaseSystemSemaphore(m_Handle, releaseCount, nullptr))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�ͷ��ź���ʧ�ܣ�"s));
	}

	m_CurrentCount += releaseCount;
}

void CoreTools::SemaphoreImpl
	::Wait()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::WaitForSystemSemaphore(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�����ź���ʧ�ܣ�"s));
	}

	--m_CurrentCount;
}

int CoreTools::SemaphoreImpl
	::GetCurrentCount() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_CurrentCount;
}

int CoreTools::SemaphoreImpl
	::GetMaximumCount() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_MaximumCount;
}