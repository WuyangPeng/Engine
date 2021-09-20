//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:13)

#include "CoreTools/CoreToolsExport.h"

#include "Date.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Date::Date(const Year& year, const Month& month, const Day& day) noexcept
    : m_Year{ year }, m_Month{ month }, m_Day{ day }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Date)

CoreTools::Year CoreTools::Date::GetYear() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Year;
}

CoreTools::Month CoreTools::Date::GetMonth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Month;
}

CoreTools::Day CoreTools::Date::GetDay() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Day;
}
