///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/16 21:59)

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
