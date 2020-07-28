// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadImpl.h"
#include "System/Threading/Thread.h" 
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Helper/PragmaWarning/Format.h" 
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/LogMacro.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ThreadImpl
	::ThreadImpl(void* function, void* userData, int processorNumber, ThreadSize stackSize)
	:m_ThreadID{ 0 }, m_Function{ function }, m_UserData{ userData }, m_ProcessorNumber{ processorNumber }, m_StackSize{ stackSize },
	 m_Thread{ System::CreateSystemThread(m_StackSize,static_cast<System::ThreadStartRoutine>(m_Function), m_UserData, &m_ThreadID) }
{
	if (m_Thread == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�̴߳���ʧ�ܣ�"s));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ThreadImpl
	::~ThreadImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	if (!System::CloseSystemThread(m_Thread))
	{
		LogAppenderIOManager::Format format{ SYSTEM_TEXT("�ͷ��̣߳�%1%��ʧ�ܡ�") };
		format % m_ThreadID;

		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< format.str()
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ThreadImpl
	::IsValid() const noexcept
{
	if (m_Thread != nullptr && m_Function != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIAN

CoreTools::ThreadImpl::ThreadingDWord CoreTools::ThreadImpl
	::GetThreadID() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ThreadID;
}

void CoreTools::ThreadImpl
	::Resume()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto result = System::ResumeSystemThread(m_Thread);
	if (result == sm_FailResult)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�ָ̻߳�ʧ�ܣ�"s));
	}
}

void CoreTools::ThreadImpl
	::Suspend()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto result = System::SuspendSystemThread(m_Thread);
	if (result == sm_FailResult)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�̹߳���ʧ�ܣ�"s));
	}
}

void CoreTools::ThreadImpl
	::Wait()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::WaitForSystemThread(m_Thread))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�ȴ��߳�ʧ�ܣ�"s));
	}
}

CoreTools::ThreadImpl::ThreadHandle CoreTools::ThreadImpl
	::GetThreadHandle() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Thread;
}

void CoreTools::ThreadImpl
	::SetThreadPriority(int priority)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (!System::SetSystemThreadPriority(m_Thread, priority))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�����߳����ȼ�ʧ�ܣ�"s));
	}
}

int CoreTools::ThreadImpl
	::GetThreadPriority() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto priority = System::GetSystemThreadPriority(m_Thread);

	if (priority == EnumCastUnderlying(System::ThreadPriority::ErrorReturn))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ȡ�߳����ȼ�ʧ�ܣ�"s));
	}
	else
	{
		return priority;
	}
}