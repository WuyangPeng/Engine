///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/01 13:04)

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
    if (System::PthreadMutexAttributeInit(&mutex.m_Attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit初始化Mutex失败。"s));
    }

    // 成功 = 0
    if (System::PthreadMutexAttributeSetType(&mutex.m_Attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype初始化Mutex失败。"s));
    }

    // 成功 = 0
    // 错误 = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
    if (System::PthreadMutexInit(&mutex.m_Attribute, &mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit初始化Mutex失败。"s));
    }
}

void CoreTools::ThreadMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // 成功 = 0
    // 错误 = EINVAL
    if (System::PthreadMutexDestroy(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("PthreadMutexDestroy销毁Mutex失败")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    // 成功 = 0
    // 错误 = EBUSY, EINVAL
    if (System::PthreadMutexAttributeDestroy(&mutex.m_Attribute) != System::PthreadResult::Successful)
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
    if (System::PthreadMutexLock(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入Mutex失败。"s));
    }
}

void CoreTools::ThreadMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // 成功 = 0
    // 错误 = EINVAL, EPERM
    if (System::PthreadMutexUnlock(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("离开Mutex失败")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

bool CoreTools::ThreadMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (System::PthreadMutexTrylock(&mutex.m_Mutex) == System::PthreadResult::Successful)
        return true;
    else
        return false;
}
