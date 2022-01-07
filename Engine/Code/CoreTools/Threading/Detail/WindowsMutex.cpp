///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 12:26)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsMutex.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::WindowsMutex::WindowsMutex() noexcept
    : ParentType{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsMutex)

void CoreTools::WindowsMutex::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mutex = System::CreateSystemMutex();

    if (mutex == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ��Mutexʧ�ܡ�"s));
    }
}

void CoreTools::WindowsMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!System::CloseSystemMutex(mutex))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("����Mutexʧ��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void CoreTools::WindowsMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!System::WaitForSystemMutex(mutex))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Mutexʧ�ܡ�"s));
    }

    // ���:
    // WAIT_ABANDONED(0x00000080)
    // WAIT_OBJECT_0(0x00000000)�����ź�
    // WAIT_TIMEOUT(0x00000102), [��INFINITE������]
    // WAIT_FAILED(0xFFFFFFFF)�����ź�
}

void CoreTools::WindowsMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!System::ReleaseSystemMutex(mutex))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("�ͷŻ�����ʧ��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

bool CoreTools::WindowsMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto result = System::WaitForSystemMutex(mutex, 0);
    if (result == System::MutexWaitReturn::Object0)
        return true;
    else
        return false;
}
