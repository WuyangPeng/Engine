//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:57)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/gsl_util>

CoreTools::ThreadImpl::ThreadImpl(void* function, void* userData, int processorNumber, ThreadSize stackSize)
    : m_ThreadID{ 0 }, m_Function{ function }, m_UserData{ userData }, m_ProcessorNumber{ processorNumber }, m_StackSize{ stackSize },
      m_Thread{ System::CreateSystemThread(m_StackSize, static_cast<System::ThreadStartRoutine>(m_Function), m_UserData, &m_ThreadID) }
{
    if (m_Thread == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程创建失败！"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ThreadImpl::~ThreadImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemThread(m_Thread))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("释放线程")
            << gsl::narrow_cast<int>(m_ThreadID)
            << SYSTEM_TEXT("失败。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ThreadImpl::IsValid() const noexcept
{
    if (m_Thread != nullptr && m_Function != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIAN

CoreTools::ThreadImpl::ThreadingDWord CoreTools::ThreadImpl::GetThreadID() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_ThreadID;
}

void CoreTools::ThreadImpl::Resume()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto result = System::ResumeSystemThread(m_Thread);
    if (result == sm_FailResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程恢复失败！"s));
    }
}

void CoreTools::ThreadImpl::Suspend()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto result = System::SuspendSystemThread(m_Thread);
    if (result == sm_FailResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("线程挂起失败！"s));
    }
}

void CoreTools::ThreadImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemThread(m_Thread))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("等待线程失败！"s));
    }
}

CoreTools::ThreadImpl::ThreadHandle CoreTools::ThreadImpl::GetThreadHandle() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Thread;
}

void CoreTools::ThreadImpl::SetThreadPriority(int priority)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::SetSystemThreadPriority(m_Thread, priority))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置线程优先级失败！"s));
    }
}

int CoreTools::ThreadImpl::GetThreadPriority() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto priority = System::GetSystemThreadPriority(m_Thread);

    if (priority == EnumCastUnderlying(System::ThreadPriority::ErrorReturn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取线程优先级失败！"s));
    }
    else
    {
        return priority;
    }
}