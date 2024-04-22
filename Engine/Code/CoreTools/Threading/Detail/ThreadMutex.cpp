/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:10)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadMutex.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ThreadMutex::ThreadMutex() noexcept
    : ParentType{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadMutex)

void CoreTools::ThreadMutex::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// 成功 = 0
    /// 错误 = ENOMEM
    if (PThreadMutexAttributeInit(&mutex.attribute) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit初始化Mutex失败。"s))
    }

    /// 成功 = 0
    if (PThreadMutexAttributeSetType(&mutex.attribute) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype初始化Mutex失败。"s))
    }

    /// 成功 = 0
    /// 错误 = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
    if (PThreadMutexInit(&mutex.attribute, &mutex.mutex) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit初始化Mutex失败。"s))
    }
}

void CoreTools::ThreadMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// 成功 = 0
    /// 错误 = EINVAL
    if (System::PThreadMutexDestroy(&mutex.mutex) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("PthreadMutexDestroy销毁Mutex失败"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    /// 成功 = 0
    /// 错误 = EBUSY, EINVAL
    if (PThreadMutexAttributeDestroy(&mutex.attribute) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("PthreadMutexattrDestroy销毁Mutex失败"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::ThreadMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// 成功 = 0
    /// 错误 = EINVAL, EDEADLK
    if (System::PThreadMutexLock(&mutex.mutex) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入Mutex失败。"s))
    }
}

void CoreTools::ThreadMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// 成功 = 0
    /// 错误 = EINVAL, EPERM
    if (System::PThreadMutexUnlock(&mutex.mutex) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("离开Mutex失败"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

bool CoreTools::ThreadMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return System::PThreadMutexTryLock(&mutex.mutex) == System::PThreadResult::Successful;
}
