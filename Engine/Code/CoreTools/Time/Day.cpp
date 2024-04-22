/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:30)

#include "CoreTools/CoreToolsExport.h"

#include "Day.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Day::Day(int day) noexcept
    : day{ day }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::Day::IsValid() const noexcept
{
    return 0 < day && day <= 31;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::Day::GetDay() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return day;
}
