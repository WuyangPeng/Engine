// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:20)

#include "CoreTools/CoreToolsExport.h"

#include "EventImpl.h"
#include "System/Threading/Event.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::EventImpl
	::EventImpl(bool manualReset, bool initialState)
	:m_Handle{ System::CreateSystemEvent(manualReset,initialState) }
{
	if (!System::IsSystemEventValid(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���¼�����ʧ�ܣ�"s));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::EventImpl
	::~EventImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	if (!System::CloseSystemEvent(m_Handle))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("�����¼�����ʧ�ܣ�")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::EventImpl
	::IsValid() const noexcept
{
	if (System::IsSystemEventValid(m_Handle))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::EventImpl
	::SetEvent()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::SetSystemEvent(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("SetEventʧ�ܣ�"s));
	}
}

void CoreTools::EventImpl
	::ResetEvent()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::ResetSystemEvent(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ResetEventʧ�ܣ�"s));
	}
}

void CoreTools::EventImpl
	::Wait()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::WaitForSystemEvent(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("����Eventʧ�ܣ�"s));
	}
}

