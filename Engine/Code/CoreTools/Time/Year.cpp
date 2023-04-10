///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:11)

#include "CoreTools/CoreToolsExport.h"

#include "Year.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Year::Year(int year) noexcept
    : year{ year }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::Year::IsValid() const noexcept
{
    if (year != 0)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::Year::GetYear() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return year;
}
