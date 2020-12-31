//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:01)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManagerImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <algorithm>
#include <functional>

using std::make_shared;
using std::mem_fn;

CoreTools::ThreadManagerImpl::ThreadManagerImpl() noexcept
    : m_Thread{}, m_ThreadHandle{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadManagerImpl)

void CoreTools::ThreadManagerImpl::AddThread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ThreadImplPtr thread{ make_shared<ThreadImpl>(function, userData, processorNumber, stackSize) };

    m_Thread.emplace_back(thread);
    m_ThreadHandle.push_back(thread->GetThreadHandle());
}

void CoreTools::ThreadManagerImpl::AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber, ThreadSize stackSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ThreadImplPtr thread{ make_shared<ThreadImpl>(function, userData, processorNumber, stackSize) };

    thread->SetThreadPriority(priority);

    m_Thread.emplace_back(thread);
}

void CoreTools::ThreadManagerImpl::Resume()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for_each(m_Thread.begin(), m_Thread.end(), mem_fn(&ThreadImpl::Resume));
}

void CoreTools::ThreadManagerImpl::Suspend()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for_each(m_Thread.begin(), m_Thread.end(), mem_fn(&ThreadImpl::Suspend));
}

void CoreTools::ThreadManagerImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto result = System::WaitForSystemThread(boost::numeric_cast<int>(m_ThreadHandle.size()), m_ThreadHandle.data(), true, EnumCastUnderlying(System::MutexWait::Infinite));

    if (result == System::MutexWaitReturn::Failed)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("等待线程失败！"s));
    }

    m_Thread.clear();
    m_ThreadHandle.clear();
}
