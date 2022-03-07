///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 13:36)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentPackage.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::CommandArgumentPackage::CommandArgumentPackage(int index, const std::string& name)
    : index{ index }, name{ name }, used{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CommandArgumentPackage::IsValid() const noexcept
{
    return (1 <= index);
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CommandArgumentPackage::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return index;
}

string CoreTools::CommandArgumentPackage::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return name;
}

bool CoreTools::CommandArgumentPackage::IsUsed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return used;
}

void CoreTools::CommandArgumentPackage::SetUsed() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    used = true;
}
