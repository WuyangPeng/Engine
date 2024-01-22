/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:19)

#include "CoreTools/CoreToolsExport.h"

#include "Year.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

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

int CoreTools::Year::GetCurrentYear()
{
    const auto currentTime = boost::posix_time::second_clock::local_time();

    return currentTime.date().year();
}
