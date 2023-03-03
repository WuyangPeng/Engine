///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 16:16)

#include "CoreTools/CoreToolsExport.h"

#include "EventImpl.h"
#include "System/Threading/Event.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::EventImpl::EventImpl(bool manualReset, bool initialState)
    : handle{ System::CreateSystemEvent(manualReset, initialState) }
{
    if (!System::IsSystemEventValid(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���¼�����ʧ�ܣ�"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::EventImpl::EventImpl(EventImpl&& rhs) noexcept
    : handle{ rhs.handle }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::EventImpl& CoreTools::EventImpl::operator=(EventImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    handle = rhs.handle;

    return *this;
}

CoreTools::EventImpl::~EventImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemEvent(handle))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("�����¼�����ʧ�ܣ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::EventImpl::IsValid() const noexcept
{
    if (System::IsSystemEventValid(handle))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::EventImpl::SetEvent() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::SetSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("SetEventʧ�ܣ�"s))
    }
}

void CoreTools::EventImpl::ResetEvent() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::ResetSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ResetEventʧ�ܣ�"s))
    }
}

void CoreTools::EventImpl::Wait() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Eventʧ�ܣ�"s))
    }
}
