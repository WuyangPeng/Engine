// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:28)

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
		THROW_EXCEPTION(SYSTEM_TEXT("初始化Mutex失败。"s));
	}
}

void CoreTools::WindowsMutex
	::Delete() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::CloseSystemMutex(m_Mutex))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("销毁Mutex失败")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

void CoreTools::WindowsMutex
	::Enter()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::WaitForSystemMutex(m_Mutex))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("进入Mutex失败。"s));
	}

	// 结果:
	// WAIT_ABANDONED(0x00000080)
	// WAIT_OBJECT_0(0x00000000)，有信号
	// WAIT_TIMEOUT(0x00000102), [对INFINITE不可能]
	// WAIT_FAILED(0xFFFFFFFF)，无信号
}

void CoreTools::WindowsMutex
	::Leave() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (!System::ReleaseSystemMutex(m_Mutex))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("释放互斥体失败")
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



