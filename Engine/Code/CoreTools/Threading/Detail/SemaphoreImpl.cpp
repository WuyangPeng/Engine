/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:06)

#include "CoreTools/CoreToolsExport.h"

#include "SemaphoreImpl.h"
#include "System/Threading/Semaphore.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::SemaphoreImpl::SemaphoreImpl(int initialCount, int maximumCount)
    : handle{ System::CreateSystemSemaphore(initialCount, maximumCount) },
      currentCount{ initialCount },
      maximumCount{ maximumCount }
{
    if (!System::IsSystemSemaphoreValid(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("初始化信号量失败！"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SemaphoreImpl::~SemaphoreImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemSemaphore(handle))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("销毁信号量失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SemaphoreImpl::IsValid() const noexcept
{
    return System::IsSystemSemaphoreValid(handle) && 0 <= currentCount && currentCount <= maximumCount;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SemaphoreImpl::Release(int releaseCount)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(0 < releaseCount, "要释放的信号量数目为负数。");

    currentCount += releaseCount;

    if (!System::ReleaseSystemSemaphore(handle, releaseCount, nullptr))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("释放信号量失败！"s))
    }
}

void CoreTools::SemaphoreImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemSemaphore(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入信号量失败！"s))
    }

    --currentCount;
}

int CoreTools::SemaphoreImpl::GetCurrentCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return currentCount;
}

int CoreTools::SemaphoreImpl::GetMaximumCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return maximumCount;
}