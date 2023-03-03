///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:22)

#include "CoreTools/CoreToolsExport.h"

#include "NullMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NullMutex::NullMutex() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullMutex)

void CoreTools::NullMutex::Initialize() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex::Enter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

bool CoreTools::NullMutex::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return true;
}
