///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:31)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/ThreadFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

CoreTools::ThreadImpl::ThreadImpl(void* function, void* userData, int processorNumber, ThreadSize stackSize)
    : threadId{ 0 },
      function{ function },
      userData{ userData },
      processorNumber{ processorNumber },
      stackSize{ stackSize },
      thread{ System::CreateSystemThread(stackSize, static_cast<System::ThreadStartRoutine>(function), userData, &threadId) }
{
    if (thread == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�̴߳���ʧ�ܣ�"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ThreadImpl::~ThreadImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemThread(thread))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�ͷ��߳�"), gsl::narrow_cast<int>(threadId), SYSTEM_TEXT("ʧ�ܡ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
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

#endif  // OPEN_CLASS_INVARIANT

CoreTools::ThreadImpl::ThreadingDWord CoreTools::ThreadImpl::GetThreadId() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return threadId;
}

void CoreTools::ThreadImpl::Resume() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto result = System::ResumeSystemThread(thread); result == failResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ָ̻߳�ʧ�ܣ�"s))
    }
}

void CoreTools::ThreadImpl::Suspend() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto result = System::SuspendSystemThread(thread); result == failResult)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�̹߳���ʧ�ܣ�"s))
    }
}

void CoreTools::ThreadImpl::Wait() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemThread(thread))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ȴ��߳�ʧ�ܣ�"s))
    }
}

CoreTools::ThreadImpl::ThreadHandle CoreTools::ThreadImpl::GetThreadHandle() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return thread;
}

void CoreTools::ThreadImpl::SetThreadPriority(int priority) const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::SetSystemThreadPriority(thread, priority))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����߳����ȼ�ʧ�ܣ�"s))
    }
}

int CoreTools::ThreadImpl::GetThreadPriority() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto priority = System::GetSystemThreadPriority(thread); priority == EnumCastUnderlying(System::ThreadPriority::ErrorReturn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ�߳����ȼ�ʧ�ܣ�"s))
    }
    else
    {
        return priority;
    }
}