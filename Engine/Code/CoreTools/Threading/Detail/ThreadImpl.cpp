///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 12:25)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

CoreTools::ThreadImpl::ThreadImpl(void* function, void* userData, int processorNumber, ThreadSize stackSize)
    : threadID{ 0 },
      function{ function },
      userData{ userData },
      processorNumber{ processorNumber },
      stackSize{ stackSize },
      thread{ System::CreateSystemThread(stackSize, static_cast<System::ThreadStartRoutine>(function), userData, &threadID) }
{
    if (thread == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程创建失败！"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ThreadImpl::~ThreadImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemThread(thread))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("释放线程")
            << gsl::narrow_cast<int>(threadID)
            << SYSTEM_TEXT("失败。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ThreadImpl::IsValid() const noexcept
{
    if (thread != nullptr && function != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIAN

CoreTools::ThreadImpl::ThreadingDWord CoreTools::ThreadImpl::GetThreadID() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return threadID;
}

void CoreTools::ThreadImpl::Resume()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto result = System::ResumeSystemThread(thread);
    if (result == failResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程恢复失败！"s));
    }
}

void CoreTools::ThreadImpl::Suspend()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto result = System::SuspendSystemThread(thread);
    if (result == failResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程挂起失败！"s));
    }
}

void CoreTools::ThreadImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemThread(thread))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("等待线程失败！"s));
    }
}

CoreTools::ThreadImpl::ThreadHandle CoreTools::ThreadImpl::GetThreadHandle() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return thread;
}

void CoreTools::ThreadImpl::SetThreadPriority(int priority)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::SetSystemThreadPriority(thread, priority))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置线程优先级失败！"s));
    }
}

int CoreTools::ThreadImpl::GetThreadPriority() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto priority = System::GetSystemThreadPriority(thread);

    if (priority == EnumCastUnderlying(System::ThreadPriority::ErrorReturn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取线程优先级失败！"s));
    }
    else
    {
        return priority;
    }
}