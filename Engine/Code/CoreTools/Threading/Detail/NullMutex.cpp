///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 12:18)

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
