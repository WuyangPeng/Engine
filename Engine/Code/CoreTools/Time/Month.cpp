//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:13)

#include "CoreTools/CoreToolsExport.h"

#include "Month.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Month::Month(int month) noexcept
    : m_Month{ month }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::Month::IsValid() const noexcept
{
    if (0 < m_Month && m_Month <= 12)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::Month::GetMonth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Month;
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

CoreTools::Month CoreTools::Month::Dec() noexcept
{
    return Month{ 12 };
}

CoreTools::Month CoreTools::Month::Nov() noexcept
{
    return Month{ 11 };
}

CoreTools::Month CoreTools::Month::Oct() noexcept
{
    return Month{ 10 };
}

CoreTools::Month CoreTools::Month::Sep() noexcept
{
    return Month{ 9 };
}

CoreTools::Month CoreTools::Month::Aug() noexcept
{
    return Month{ 8 };
}

CoreTools::Month CoreTools::Month::Jul() noexcept
{
    return Month{ 7 };
}

CoreTools::Month CoreTools::Month::Jun() noexcept
{
    return Month{ 6 };
}

CoreTools::Month CoreTools::Month::May() noexcept
{
    return Month{ 5 };
}

CoreTools::Month CoreTools::Month::Apr() noexcept
{
    return Month{ 4 };
}
