//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:53)

#include "CoreTools/CoreToolsExport.h"

#include "SemaphoreImpl.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 

CoreTools::SemaphoreImpl::SemaphoreImpl(int initialCount, int maximumCount)
    : m_Handle{ System::CreateSystemSemaphore(initialCount, maximumCount) },
      m_CurrentCount{ initialCount }, m_MaximumCount{ maximumCount }
{
    if (!System::IsSystemSemaphoreValid(m_Handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("初始化信号量失败！"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SemaphoreImpl::~SemaphoreImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemSemaphore(m_Handle))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("销毁信号量失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SemaphoreImpl::IsValid() const noexcept
{
    if (System::IsSystemSemaphoreValid(m_Handle) && 0 <= m_CurrentCount && m_CurrentCount <= m_MaximumCount)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SemaphoreImpl::Release(int releaseCount)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_1(0 < releaseCount, "要释放的信号量数目为负数。");

    if (!System::ReleaseSystemSemaphore(m_Handle, releaseCount, nullptr))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("释放信号量失败！"s));
    }

    m_CurrentCount += releaseCount;
}

void CoreTools::SemaphoreImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemSemaphore(m_Handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入信号量失败！"s));
    }

    --m_CurrentCount;
}

int CoreTools::SemaphoreImpl::GetCurrentCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CurrentCount;
}

int CoreTools::SemaphoreImpl::GetMaximumCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_MaximumCount;
}