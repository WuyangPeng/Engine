//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:13)

#include "CoreTools/CoreToolsExport.h"

#include "Day.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Day::Day(int day) noexcept
    : m_Day{ day }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::Day::IsValid() const noexcept
{
    if (0 < m_Day && m_Day <= 31)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::Day::GetDay() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Day;
}
