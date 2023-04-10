///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:39)

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
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���ź���ʧ�ܣ�"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SemaphoreImpl::~SemaphoreImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemSemaphore(handle))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�����ź���ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SemaphoreImpl::IsValid() const noexcept
{
    if (System::IsSystemSemaphoreValid(handle) && 0 <= currentCount && currentCount <= maximumCount)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SemaphoreImpl::Release(int releaseCount)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_1(0 < releaseCount, "Ҫ�ͷŵ��ź�����ĿΪ������");

    currentCount += releaseCount;

    if (!System::ReleaseSystemSemaphore(handle, releaseCount, nullptr))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�ͷ��ź���ʧ�ܣ�"s))
    }
}

void CoreTools::SemaphoreImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemSemaphore(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ź���ʧ�ܣ�"s))
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