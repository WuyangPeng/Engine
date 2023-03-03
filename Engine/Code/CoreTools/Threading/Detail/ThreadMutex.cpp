///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 17:25)

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

    // 成功 = 0
    // 错误 = ENOMEM
    if (PthreadMutexAttributeInit(&mutex.attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit初始化Mutex失败。"s))
    }

    // 成功 = 0
    if (PthreadMutexAttributeSetType(&mutex.attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype初始化Mutex失败。"s))
    }

    // 成功 = 0
    // 错误 = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
    if (PthreadMutexInit(&mutex.attribute, &mutex.mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit初始化Mutex失败。"s))
    }
}

void CoreTools::ThreadMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // 成功 = 0
    // 错误 = EINVAL
    if (System::PthreadMutexDestroy(&mutex.mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("PthreadMutexDestroy销毁Mutex失败")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    // 成功 = 0
    // 错误 = EBUSY, EINVAL
    if (PthreadMutexAttributeDestroy(&mutex.attribute) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("PthreadMutexattrDestroy销毁Mutex失败")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void CoreTools::ThreadMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // 成功 = 0
    // 错误 = EINVAL, EDEADLK
    if (System::PthreadMutexLock(&mutex.mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入Mutex失败。"s))
    }
}

void CoreTools::ThreadMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // 成功 = 0
    // 错误 = EINVAL, EPERM
    if (System::PthreadMutexUnlock(&mutex.mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("离开Mutex失败")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

bool CoreTools::ThreadMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (System::PthreadMutexTrylock(&mutex.mutex) == System::PthreadResult::Successful)
        return true;
    else
        return false;
}
