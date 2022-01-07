///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:36)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestData.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::UnitTestData::UnitTestData() noexcept
    : pass{ 0 }, fail{ 0 }, error{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestData::IsValid() const noexcept
{
    if (0 <= fail && 0 <= pass && 0 <= error)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::UnitTestData::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return pass;
}

int CoreTools::UnitTestData::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return fail;
}

int CoreTools::UnitTestData::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return error;
}

bool CoreTools::UnitTestData::IsEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return (pass == 0) && (fail == 0) && (error == 0);
}

void CoreTools::UnitTestData::AddPassedNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ++pass;
}

void CoreTools::UnitTestData::AddFailedNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (fail == 0)
    {
        System::SystemPause();
    }

    ++fail;
}

void CoreTools::UnitTestData::AddErrorNumber() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (error == 0)
    {
        System::SystemPause();
    }

    ++error;
}

void CoreTools::UnitTestData::ClearData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    pass = 0;
    fail = 0;
    error = 0;
}
