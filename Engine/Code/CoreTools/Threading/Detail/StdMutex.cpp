//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:53)

#include "CoreTools/CoreToolsExport.h"

#include "StdMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::StdMutex::StdMutex() noexcept
    : ParentType{}, m_Mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdMutex)

void CoreTools::StdMutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Mutex.lock();
}

void CoreTools::StdMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        DoLeave();
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

void CoreTools::StdMutex::DoLeave()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26110)

    m_Mutex.unlock();

#include STSTEM_WARNING_POP
}

bool CoreTools::StdMutex::TryEnter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_Mutex.try_lock();
}
