// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:25)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManagerImpl.h"
#include "System/Threading/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <functional>
#include <algorithm>

using std::make_shared;
using std::mem_fn;

CoreTools::ThreadManagerImpl
	::ThreadManagerImpl() noexcept
	:m_Thread{}, m_ThreadHandle{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadManagerImpl)

void CoreTools::ThreadManagerImpl
	::AddThread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ThreadImplPtr thread{ make_shared<ThreadImpl>(function,userData,processorNumber,stackSize) };

	m_Thread.push_back(thread);
	m_ThreadHandle.push_back(thread->GetThreadHandle());
}

void CoreTools::ThreadManagerImpl
	::AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber, ThreadSize stackSize)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	ThreadImplPtr thread{ make_shared<ThreadImpl>(function,userData,processorNumber,stackSize) };

	thread->SetThreadPriority(priority);

	m_Thread.push_back(thread);
}

void CoreTools::ThreadManagerImpl
	::Resume()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	for_each(m_Thread.begin(), m_Thread.end(), mem_fn(&ThreadImpl::Resume));
}

void CoreTools::ThreadManagerImpl
	::Suspend()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	for_each(m_Thread.begin(), m_Thread.end(), mem_fn(&ThreadImpl::Suspend));
}

void CoreTools::ThreadManagerImpl
	::Wait()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	const auto result = System::WaitForSystemThread(boost::numeric_cast<int>(m_ThreadHandle.size()), m_ThreadHandle.data(), true, EnumCastUnderlying(System::MutexWait::Infinite));

	if (result == System::MutexWaitReturn::Failed)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("µ»¥˝œﬂ≥Ã ß∞‹£°"s));
	}

	m_Thread.clear();
	m_ThreadHandle.clear();
}

