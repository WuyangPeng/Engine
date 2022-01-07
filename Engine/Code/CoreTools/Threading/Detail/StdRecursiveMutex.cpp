///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 12:24)

#include "CoreTools/CoreToolsExport.h"

#include "StdRecursiveMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

CoreTools::StdRecursiveMutex::StdRecursiveMutex() noexcept
    : ParentType{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StdRecursiveMutex)

void CoreTools::StdRecursiveMutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdRecursiveMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::StdRecursiveMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mutex.lock();
}

void CoreTools::StdRecursiveMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        DoLeave();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKOWN_CATCH(CoreTools)
}

void CoreTools::StdRecursiveMutex::DoLeave()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26110)

    mutex.unlock();

#include STSTEM_WARNING_POP
}

bool CoreTools::StdRecursiveMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return mutex.try_lock();
}
