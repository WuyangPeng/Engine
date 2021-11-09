///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 13:04)

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

    // �ɹ� = 0
    // ���� = ENOMEM
    if (System::PthreadMutexAttributeInit(&mutex.m_Attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrInit��ʼ��Mutexʧ�ܡ�"s));
    }

    // �ɹ� = 0
    if (System::PthreadMutexAttributeSetType(&mutex.m_Attribute) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexattrSettype��ʼ��Mutexʧ�ܡ�"s));
    }

    // �ɹ� = 0
    // ���� = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
    if (System::PthreadMutexInit(&mutex.m_Attribute, &mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("PthreadMutexInit��ʼ��Mutexʧ�ܡ�"s));
    }
}

void CoreTools::ThreadMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // �ɹ� = 0
    // ���� = EINVAL
    if (System::PthreadMutexDestroy(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("PthreadMutexDestroy����Mutexʧ��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    // �ɹ� = 0
    // ���� = EBUSY, EINVAL
    if (System::PthreadMutexAttributeDestroy(&mutex.m_Attribute) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("PthreadMutexattrDestroy����Mutexʧ��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void CoreTools::ThreadMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // �ɹ� = 0
    // ���� = EINVAL, EDEADLK
    if (System::PthreadMutexLock(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Mutexʧ�ܡ�"s));
    }
}

void CoreTools::ThreadMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    // �ɹ� = 0
    // ���� = EINVAL, EPERM
    if (System::PthreadMutexUnlock(&mutex.m_Mutex) != System::PthreadResult::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("�뿪Mutexʧ��")
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
