///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:39)

#include "CoreTools/CoreToolsExport.h"

#include "BoostRecursiveMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BoostRecursiveMutex::BoostRecursiveMutex() noexcept
    : ParentType{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BoostRecursiveMutex)

void CoreTools::BoostRecursiveMutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostRecursiveMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::BoostRecursiveMutex::Enter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mutex.lock();
}

void CoreTools::BoostRecursiveMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        mutex.unlock();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
    EXCEPTION_UNKNOWN_CATCH(CoreTools)
}

bool CoreTools::BoostRecursiveMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return mutex.try_lock();
}
