///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 22:50)

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
        THROW_EXCEPTION(SYSTEM_TEXT("初始化事件对象失败！"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::EventImpl::~EventImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    if (!System::CloseSystemEvent(handle))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("销毁事件对象失败！")
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

void CoreTools::EventImpl::SetEvent()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::SetSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("SetEvent失败！"s));
    }
}

void CoreTools::EventImpl::ResetEvent()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::ResetSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ResetEvent失败！"s));
    }
}

void CoreTools::EventImpl::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (!System::WaitForSystemEvent(handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("进入Event失败！"s));
    }
}
