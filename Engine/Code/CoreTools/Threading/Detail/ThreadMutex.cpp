/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:10)

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

    /// �ɹ� = 0
    /// ���� = ENOMEM
    if (PThreadMutexAttributeInit(&mutex.attribute) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit��ʼ��Mutexʧ�ܡ�"s))
    }

    /// �ɹ� = 0
    if (PThreadMutexAttributeSetType(&mutex.attribute) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype��ʼ��Mutexʧ�ܡ�"s))
    }

    /// �ɹ� = 0
    /// ���� = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
    if (PThreadMutexInit(&mutex.attribute, &mutex.mutex) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit��ʼ��Mutexʧ�ܡ�"s))
    }
}

void CoreTools::ThreadMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// �ɹ� = 0
    /// ���� = EINVAL
    if (System::PThreadMutexDestroy(&mutex.mutex) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("PthreadMutexDestroy����Mutexʧ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    /// �ɹ� = 0
    /// ���� = EBUSY, EINVAL
    if (PThreadMutexAttributeDestroy(&mutex.attribute) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("PthreadMutexattrDestroy����Mutexʧ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::ThreadMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// �ɹ� = 0
    /// ���� = EINVAL, EDEADLK
    if (System::PThreadMutexLock(&mutex.mutex) != System::PThreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Mutexʧ�ܡ�"s))
    }
}

void CoreTools::ThreadMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    /// �ɹ� = 0
    /// ���� = EINVAL, EPERM
    if (System::PThreadMutexUnlock(&mutex.mutex) != System::PThreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�뿪Mutexʧ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

bool CoreTools::ThreadMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return System::PThreadMutexTryLock(&mutex.mutex) == System::PThreadResult::Successful;
}
