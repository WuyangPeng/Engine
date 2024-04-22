/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:10)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManagerImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <algorithm>
#include <functional>

CoreTools::ThreadManagerImpl::ThreadManagerImpl() noexcept
    : thread{}, threadHandle{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadManagerImpl)

void CoreTools::ThreadManagerImpl::AddThread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto threadImpl = std::make_shared<ThreadImpl>(function, userData, processorNumber, stackSize);

    thread.emplace_back(threadImpl);
    threadHandle.emplace_back(threadImpl->GetThreadHandle());
}

void CoreTools::ThreadManagerImpl::AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber, ThreadSize stackSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto threadImpl = std::make_shared<ThreadImpl>(function, userData, processorNumber, stackSize);
    threadImpl->SetThreadPriority(priority);

    thread.emplace_back(threadImpl);
    threadHandle.emplace_back(threadImpl->GetThreadHandle());
}

void CoreTools::ThreadManagerImpl::Resume()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::ranges::for_each(thread, std::mem_fn(&ThreadImpl::Resume));
}

void CoreTools::ThreadManagerImpl::Suspend()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::ranges::for_each(thread, std::mem_fn(&ThreadImpl::Suspend));
}

void CoreTools::ThreadManagerImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (const auto result = System::WaitForSystemThread(boost::numeric_cast<int>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(System::MutexWait::Infinite));
        result == System::MutexWaitReturn::Failed)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("等待线程失败！"s))
    }

    thread.clear();
    threadHandle.clear();
}
