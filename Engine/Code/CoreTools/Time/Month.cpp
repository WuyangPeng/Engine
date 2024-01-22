/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:19)

#include "CoreTools/CoreToolsExport.h"

#include "Month.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Month::Month(int month) noexcept
    : month{ month }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::Month::IsValid() const noexcept
{
    if (0 < month && month <= 12)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::Month::GetMonth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return month;
}

CoreTools::Month CoreTools::Month::Jan() noexcept
{
    return Month{ 1 };
}

CoreTools::Month CoreTools::Month::Feb() noexcept
{
    return Month{ 2 };
}

CoreTools::Month CoreTools::Month::Mar() noexcept
{
    return Month{ 3 };
}

CoreTools::Month CoreTools::Month::Apr() noexcept
{
    return Month{ 4 };
}

CoreTools::Month CoreTools::Month::May() noexcept
{
    return Month{ 5 };
}

CoreTools::Month CoreTools::Month::Jun() noexcept
{
    return Month{ 6 };
}

CoreTools::Month CoreTools::Month::Jul() noexcept
{
    return Month{ 7 };
}

CoreTools::Month CoreTools::Month::Aug() noexcept
{
    return Month{ 8 };
}

CoreTools::Month CoreTools::Month::Sep() noexcept
{
    return Month{ 9 };
}

CoreTools::Month CoreTools::Month::Oct() noexcept
{
    return Month{ 10 };
}

CoreTools::Month CoreTools::Month::Nov() noexcept
{
    return Month{ 11 };
}

CoreTools::Month CoreTools::Month::Dec() noexcept
{
    return Month{ 12 };
}
