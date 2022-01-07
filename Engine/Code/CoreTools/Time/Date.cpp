///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:54)

#include "CoreTools/CoreToolsExport.h"

#include "Date.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Date::Date(const Year& year, const Month& month, const Day& day) noexcept
    : year{ year }, month{ month }, day{ day }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Date)

CoreTools::Year CoreTools::Date::GetYear() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return year;
}

CoreTools::Month CoreTools::Date::GetMonth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return month;
}

CoreTools::Day CoreTools::Date::GetDay() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return day;
}
