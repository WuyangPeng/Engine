// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsMutex.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WindowsMutex
	::WindowsMutex() noexcept
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsMutex)

void CoreTools::WindowsMutex
	::Initialize()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Mutex = System::CreateSystemMutex();

	if (m_Mutex == nullptr)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ʼ��Mutexʧ�ܡ�"s));
	}
}

void CoreTools::WindowsMutex
	::Delete() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::CloseSystemMutex(m_Mutex))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("����Mutexʧ��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

void CoreTools::WindowsMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::WaitForSystemMutex(m_Mutex))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("����Mutexʧ�ܡ�"s));
	}

	// ���:
	// WAIT_ABANDONED(0x00000080)
	// WAIT_OBJECT_0(0x00000000)�����ź�
	// WAIT_TIMEOUT(0x00000102), [��INFINITE������]
	// WAIT_FAILED(0xFFFFFFFF)�����ź�
}

void CoreTools::WindowsMutex
	::Leave() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::ReleaseSystemMutex(m_Mutex))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("�ͷŻ�����ʧ��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

bool CoreTools::WindowsMutex
	::TryEnter() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	const auto result = System::WaitForSystemMutex(m_Mutex, 0);
	if (result == System::MutexWaitReturn::Object0)
		return true;
	else
		return false;
}



