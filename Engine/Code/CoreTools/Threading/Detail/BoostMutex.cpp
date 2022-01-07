///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:22)

#include "CoreTools/CoreToolsExport.h"

#include "BoostMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BoostMutex::BoostMutex() noexcept
    : ParentType{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostMutex)

void CoreTools::BoostMutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mutex.lock();
}

void CoreTools::BoostMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        mutex.unlock();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKOWN_CATCH(CoreTools)
}

bool CoreTools::BoostMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return mutex.try_lock();
}
