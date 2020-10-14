//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:40)

#include "CoreTools/CoreToolsExport.h"

#include "BoostRecursiveMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 

CoreTools::BoostRecursiveMutex::BoostRecursiveMutex() noexcept
    : ParentType{}, m_Mutex{}
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

    m_Mutex.lock();
}

void CoreTools::BoostRecursiveMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        m_Mutex.unlock();
    }
    EXCEPTION_STD_EXCEPTION_CATCH(CoreTools)
}

bool CoreTools::BoostRecursiveMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_Mutex.try_lock();
}
