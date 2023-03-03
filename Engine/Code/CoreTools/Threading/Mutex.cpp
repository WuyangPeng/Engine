///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 17:34)

#include "CoreTools/CoreToolsExport.h"

#include "Mutex.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::Mutex::Mutex(MutexCreate mutexCreate)
    : ParentType{ mutexCreate }
{
    ParentType::Initialize();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Mutex::Mutex(Mutex&& rhs) noexcept
    : ParentType{ std::move(rhs) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Mutex& CoreTools::Mutex::operator=(Mutex&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        ParentType::operator=(std::move(rhs));
    }

    return *this;
}

CoreTools::Mutex::~Mutex() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ParentType::Delete();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Mutex)

void CoreTools::Mutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

void CoreTools::Mutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}
