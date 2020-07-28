// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadMutex.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ThreadMutex
	::ThreadMutex()
	:m_Mutex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ThreadMutex
	::~ThreadMutex()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadMutex)

void CoreTools::ThreadMutex
	::Initialize()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	// �ɹ� = 0
	// ���� = ENOMEM
	if (System::PthreadMutexAttributeInit(&m_Mutex.m_Attribute) != System::PthreadResult::Successful)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit��ʼ��Mutexʧ�ܡ�"s));
	}

	// �ɹ� = 0
	if (System::PthreadMutexAttributeSetType(&m_Mutex.m_Attribute) != System::PthreadResult::Successful)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype��ʼ��Mutexʧ�ܡ�"s));
	}

	// �ɹ� = 0
	// ���� = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
	if (System::PthreadMutexInit(&m_Mutex.m_Attribute, &m_Mutex.m_Mutex) != System::PthreadResult::Successful)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit��ʼ��Mutexʧ�ܡ�"s));
	}
}

void CoreTools::ThreadMutex
	::Delete()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	// �ɹ� = 0
	// ���� = EINVAL
	if (System::PthreadMutexDestroy(&m_Mutex.m_Mutex) != System::PthreadResult::Successful)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("PthreadMutexDestroy����Mutexʧ��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}

	// �ɹ� = 0
	// ���� = EBUSY, EINVAL
	if (System::PthreadMutexAttributeDestroy(&m_Mutex.m_Attribute) != System::PthreadResult::Successful)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("PthreadMutexattrDestroy����Mutexʧ��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

void CoreTools::ThreadMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	// �ɹ� = 0
	// ���� = EINVAL, EDEADLK
	if (System::PthreadMutexLock(&m_Mutex.m_Mutex) != System::PthreadResult::Successful)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("����Mutexʧ�ܡ�"s));
	}
}

void CoreTools::ThreadMutex
	::Leave()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	// �ɹ� = 0
	// ���� = EINVAL, EPERM
	if (System::PthreadMutexUnlock(&m_Mutex.m_Mutex) != System::PthreadResult::Successful)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("�뿪Mutexʧ��")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

bool CoreTools::ThreadMutex
	::TryEnter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (System::PthreadMutexTrylock(&m_Mutex.m_Mutex) == System::PthreadResult::Successful)
		return true;
	else
		return false;
}


